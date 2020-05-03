#!/bin/sh

g++ src/hash_demo.cpp src/list.cpp src/hash_entry.cpp src/hash_table.cpp -w -std=c++14 -o hash_demo
g++ src/list_tree_demo.cpp src/list.cpp src/hash_entry.cpp src/tree.cpp -w -std=c++14 -o list_tree_demo
g++ src/stack_demo.cpp src/list_stack.cpp src/vector_stack.cpp -w -std=c++14 -o stack_demo
