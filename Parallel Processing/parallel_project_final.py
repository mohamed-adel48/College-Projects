# -*- coding: utf-8 -*-
"""Parallel_Project_Final.ipynb

Automatically generated by Colab.

#Import
"""

import threading
import time
import random

"""#Bubble Sort"""

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

def parallel_bubble_sort(arr):
    threads = []
    # Split the array and sort each part in a separate thread
    # Assuming a simple two-way split for illustration
    mid = len(arr) // 2
    t1 = threading.Thread(target=bubble_sort, args=(arr[:mid],))
    t2 = threading.Thread(target=bubble_sort, args=(arr[mid:],))
    threads.append(t1)
    threads.append(t2)

    # Start the threads
    for t in threads:
        t.start()

    # Wait for all threads to complete
    for t in threads:
        t.join()

    # Merge the sorted halves (This part is sequential)
    i, j, k = 0, mid, 0
    temp = arr.copy()
    while i < mid and j < len(arr):
        if arr[i] < arr[j]:
            temp[k] = arr[i]
            i += 1
        else:
            temp[k] = arr[j]
            j += 1
        k += 1

    while i < mid:
        temp[k] = arr[i]
        i += 1
        k += 1

    while j < len(arr):
        temp[k] = arr[j]
        j += 1
        k += 1

    for i in range(len(arr)):
        arr[i] = temp[i]

"""#Quick Sort"""

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

def parallel_quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = []
    right = []

    threads = []
    t1 = threading.Thread(target=lambda: left.extend(quick_sort([x for x in arr if x < pivot])))
    t2 = threading.Thread(target=lambda: right.extend(quick_sort([x for x in arr if x > pivot])))
    threads.append(t1)
    threads.append(t2)

    for t in threads:
        t.start()

    for t in threads:
        t.join()

    middle = [x for x in arr if x == pivot]
    return left + middle + right

"""#Merge Sort"""

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]

        merge_sort(L)
        merge_sort(R)

        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

def parallel_merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]

        threads = []
        t1 = threading.Thread(target=merge_sort, args=(L,))
        t2 = threading.Thread(target=merge_sort, args=(R,))
        threads.append(t1)
        threads.append(t2)

        for t in threads:
            t.start()

        for t in threads:
            t.join()

        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

"""#Depth-First Search (DFS)"""

def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    for next in graph[start] - visited:
        dfs(graph, next, visited)
    return visited

def parallel_dfs(graph, start):
    visited = set()
    visited.add(start)
    threads = []
    for next in graph[start] - visited:
        t = threading.Thread(target=dfs, args=(graph, next, visited))
        threads.append(t)
        t.start()

    for t in threads:
        t.join()

    return visited

"""#Comparison"""

def generate_random_numbers(n=500, lower_bound=0, upper_bound=1000):
    return [random.randint(lower_bound, upper_bound) for _ in range(n)]

def generate_random_graph(num_nodes=20, num_edges=50):
    if num_edges < num_nodes - 1:
        raise ValueError("Number of edges must be at least num_nodes - 1 to ensure connectivity")

    graph = {i: set() for i in range(num_nodes)}

    # Ensuring the graph is connected
    for i in range(1, num_nodes):
        connect_to = random.randint(0, i - 1)
        graph[i].add(connect_to)
        graph[connect_to].add(i)

    # Adding additional edges
    for _ in range(num_edges - (num_nodes - 1)):
        a, b = random.sample(range(num_nodes), 2)
        graph[a].add(b)
        graph[b].add(a)

    return graph

def test_algorithms():
    # Generate a random list of 500 numbers
    random_list = generate_random_numbers()

    # Testing sorting algorithms
    print("Testing Sorting Algorithms...")
    start_time = time.time()
    bubble_sort(random_list.copy())
    print("Sequential Bubble Sort Time:", time.time() - start_time)

    start_time = time.time()
    quick_sort(random_list.copy())
    print("Sequential Quick Sort Time:", time.time() - start_time)

    start_time = time.time()
    merge_sort(random_list.copy())
    print("Sequential Merge Sort Time:", time.time() - start_time)

    print("----------------------------------------------------------------------")

    start_time = time.time()
    parallel_bubble_sort(random_list.copy())
    print("Parallel Bubble Sort Time:", time.time() - start_time)

    start_time = time.time()
    parallel_quick_sort(random_list.copy())
    print("Parallel Quick Sort Time:", time.time() - start_time)

    start_time = time.time()
    parallel_merge_sort(random_list.copy())
    print("Parallel Merge Sort Time:", time.time() - start_time)

    # Testing DFS
    print("\nTesting DFS Algorithm...")
    random_graph = generate_random_graph()
    start_node = random.choice(list(random_graph.keys()))

    start_time = time.time()
    dfs(random_graph, start_node)
    print("Sequential DFS Time:", time.time() - start_time)

    start_time = time.time()
    parallel_dfs(random_graph, start_node)
    print("Parallel DFS Time:", time.time() - start_time)

# Call the test function
test_algorithms()

