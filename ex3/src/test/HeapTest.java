package test;

import java.util.Comparator;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import org.junit.Before;
import org.junit.Test;

import minheap.MinHeap;

public class HeapTest {

	class IntegerComparator implements Comparator<Integer> {
		@Override
		public int compare(Integer i1, Integer i2) {
			return i1.compareTo(i2);
		}
	}

	private static int arr_size = 10;
	private MinHeap<Integer> heap;

	@Before
	public void createHeap() {
		// fill the array 10 incrementale numbers
		heap = new MinHeap<Integer>(new IntegerComparator());
		for (int i = 100; i < arr_size + 100; i++)
			heap.insert(i);
	}

	@Test
	public void testInsert() {
		heap.insert(11);
		assertEquals(heap.length(), 11);
	}

	@Test
	public void testRemove() {
		;
		assertTrue(heap.remove() == 100 && heap.length() == 9);
	}

	@Test
	public void testPeek() {
		assertEquals((int) heap.peek(), 100);
	}

	@Test
	public void testLength() {
		assertEquals(heap.length(), 10);
	}

	@Test
	public void testTrueLeftIndex() {
		assertEquals(heap.getLeftIndex(100), 1);
	}

	@Test
	public void testFalseRightIndex() {
		assertEquals(heap.getRightIndex(109), -1);
	}
}
