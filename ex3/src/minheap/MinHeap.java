package minheap;

import java.util.ArrayList;
import java.util.Hashtable;

import java.util.Comparator;

public class MinHeap<T> {

  private ArrayList<T> heap;
  Comparator<? super T> comparator = null;
  private Hashtable<T, Integer> hash = new Hashtable<T, Integer>();

  /**
   * Costructor with no initial elements
   * 
   * @param comparator
   */
  public MinHeap(Comparator<? super T> comparator) {
    if (comparator == null) {
      throw new IllegalArgumentException("Comparator cannot be null");
    }
    this.heap = new ArrayList<T>();
    this.comparator = comparator;
  }

  /**
   * Constructor with initial elements
   * 
   * @param array
   * @param comparator
   */
  public MinHeap(ArrayList<T> array, Comparator<? super T> comparator) {
    if (comparator == null) {
      throw new IllegalArgumentException("Comparator cannot be null");
    }
    heap = new ArrayList<T>();
    this.comparator = comparator;
    for (int i = 0; i < array.size(); i++)
      insert(array.get(i));
  }

  /**
   * Return true if the element have a parent
   * 
   * @param i
   * @return
   */
  private boolean hasParent(int i) {
    if (i != 0)
      return true;
    return false;
  }

  /**
   * Return the value of the parent
   * 
   * @param i
   * @return
   */
  private T parent(int i) {
    return this.heap.get(parentIndex(i));
  }

  /**
   * Return the index of the parent
   * 
   * @param i
   * @return the index of the parent
   */
  private int parentIndex(int i) {
    if (i % 2 == 1) {
      return i / 2;
    }
    return (i - 1) / 2;
  }

  /**
   * Move a new elemnt to the right position
   */
  private void moveUp(int index) {
    while (hasParent(index) && (comparator.compare(parent(index), heap.get(index)) > 0)) {
      swap(index, parentIndex(index));
      index = parentIndex(index);
    }
    hash.put(heap.get(index), index);
  }

  /**
   * After remove the root, move the last element to the root and move it down to
   * the right position
   */
  private void moveDown() {
    int index = 0;
    while (hasLeftChild(index) || hasRightChild(index)) {
      if (hasLeftChild(index) && hasRightChild(index)) {
        if (comparator.compare(heap.get(leftIndex(index)), heap.get(rightIndex(index))) < 0) {
          // swap left and parent
          swap(index, leftIndex(index));
          index = leftIndex(index);
        } else {
          swap(index, rightIndex(index));
          index = rightIndex(index);
        }
      } else if (hasLeftChild(index)) {
        if (comparator.compare(heap.get(leftIndex(index)), heap.get(index)) < 0) {
          swap(index, leftIndex(index));
          index = leftIndex(index);
        } else
          break;
      } else if (hasRightChild(index)) {
        if (comparator.compare(heap.get(rightIndex(index)), heap.get(index)) < 0) {
          swap(index, rightIndex(index));
          index = rightIndex(index);
        } else
          break;
      } else
        break;
    }
  }

  /**
   * return index of the right child
   * 
   * @param i
   * @return the index of the right child
   */
  private int rightIndex(int i) {
    return i * 2 + 2;
  }

  /**
   * return index of the left child
   * 
   * @param i
   * @return the index of the left child
   */
  private int leftIndex(int i) {
    return i * 2 + 1;
  }

  /**
   * return if exist a lest child
   * 
   * @param i
   * @return true if exist a left child
   */
  private boolean hasLeftChild(int i) {
    if (leftIndex(i) < heap.size())
      return true;
    return false;
  }

  /**
   * return if exist a right child
   * 
   * @param i
   * @return true if exist a right child
   */
  private boolean hasRightChild(int i) {
    if (rightIndex(i) < heap.size())
      return true;
    return false;
  }

  /**
   * swap two elements
   * 
   * @param i
   * @param j
   */
  private void swap(int i, int j) {
    T temp = this.heap.get(i);
    this.heap.set(i, this.heap.get(j));
    this.heap.set(j, temp);
    this.hash.put(heap.get(i), i);
    this.hash.put(heap.get(j),j);
  }

  /**
   * inter a new element to the heap
   * 
   * @param value
   */
  public void insert(T value) {
    this.heap.add(value);
    moveUp(heap.size() - 1);
  }

  /**
   * return the size of the heap
   * 
   * @return the size of the heap
   */
  public int getSize() {
    return this.heap.size();
  }

  /**
   * check if the heap is empty
   * 
   * @return true if the heap is empty
   */
  public boolean isEmpty() {
    if (this.heap.size() == 0)
      return true;
    return false;
  }

  /**
   * function use by the user to get the parent of one element
   * 
   * @param value
   * @return the parent of the element
   */
  public T getParent(T value) {
    int i = this.hash.get(value);
    if (i == 0)
      return null;
    return this.heap.get(parentIndex(i));
  }

  /**
   * function use by the user to get the left child of one element
   * 
   * @param value
   * @return the left child of the element
   */
  public T getLeftChild(T value) {
    int i = this.hash.get(value);
    if (heap.size() >= leftIndex(i))
      return this.heap.get(2 * leftIndex(i));
    return null;
  }

  /**
   * function use by the user to get the right child of one element
   * 
   * @param value
   * @return the right child of the element or null if there is no right child
   */
  public T getRightChild(T value) {
    int i = this.hash.get(value);
    if (heap.size() >= rightIndex(i))
      return this.heap.get(rightIndex(i));
    // error
    return null;
  }

  public int getLeftIndex(T value) {
    int i = leftIndex(this.hash.get(value));
    if (i > 0 && i < this.heap.size())
      return i;
    else
      return -1;
  }

  public int getRightIndex(T value) {
    int i = rightIndex(this.hash.get(value));
    if (i > 0 && i < this.heap.size())
      return i;
    else
      return -1;
  }

  /**
   * function use by the user to get the length of the heap
   * 
   * @return the length of the heap
   */
  public int length() {
    return this.heap.size();
  }

  /**
   * function use by the user to get the root of the heap
   * 
   * @return the root of the heap
   */
  public T peek() {
    if (isEmpty())
      throw new IllegalStateException();
    return this.heap.get(0);
  }

  /**
   * function use by the user to remove the root of the heap
   * 
   * @return the root of the heap
   */
  public T remove() {
    T element = this.heap.get(0);
    heap.set(0, heap.get(heap.size() - 1));
    heap.remove(heap.size() - 1);
    moveDown();
    return element;
  }

  /**
   * use by the user to chage the value of one element with a new smaller value
   * 
   * @param value
   * @param newValue
   * @return true if the value is changed
   */
  public boolean decrease(T value, T newValue) {
    // error newValue > value
    if (comparator.compare(newValue, value) > 0)
      throw new IllegalArgumentException("Key is larger than the original key");
    // check null
    if (this.hash.get(value) == null)
      throw new IllegalArgumentException("Key is not in the heap");
    // set new value
    int index = hash.get(value);
    hash.remove(value);
    heap.set(index, newValue);
    moveUp(index);
    return true;
  }

  /**
   * use by the user to print the heap
   * 
   * @return the heap
   */
  public void print() {
    System.out.print("<--");
    for (int i = 0; i < this.heap.size(); i++)
      System.out.print("| " + this.heap.get(i) + " ");
    System.out.print(" |-->");
    System.out.println();
  }

  public int getIndex(T value) {
    return this.hash.get(value);
  }
}
