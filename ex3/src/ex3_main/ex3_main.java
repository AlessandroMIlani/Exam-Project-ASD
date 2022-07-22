//main file

package ex3_main;

import java.util.Comparator;

import minheap.MinHeap;

public class ex3_main {

	public static void main(String[] args) {

		// create array 20 random elemnets
		int[] array = new int[20];
		for (int i = 0; i < array.length; i++) {
			array[i] = (int) (Math.random() * 100);
		}

		// create heap
		MinHeap<Integer> elemts;
		elemts = new MinHeap<Integer>(new IntegerComparator());

		// fill the heap
		for (int i = 0; i < array.length; i++) {
			elemts.insert(array[i]);
		}

		// print the heap

		System.out.println("Length = " + elemts.length());
		System.out.println("Peek = " + elemts.peek());
		elemts.print();
		System.out.println("Remove:" + elemts.remove());
		// print heap
		elemts.print();
		System.out.println("Peek = " + elemts.peek());

	}
}

class IntegerComparator implements Comparator<Integer> {
	@Override
	public int compare(Integer i1, Integer i2) {
		return i1.compareTo(i2);
	}
}