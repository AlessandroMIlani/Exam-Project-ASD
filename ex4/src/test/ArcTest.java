//junit test

package test;

import java.util.ArrayList;
import java.util.Comparator;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import org.junit.Before;
import org.junit.Test;

import lib.*;

public class ArcTest {
	private Arc<String, Float> arc1;
	private Node<String, Float> start, end;

	@Before
	public void SetUp() {
		start = new Node<String, Float>("start_value");
		end = new Node<String, Float>("end_value");
		arc1 = new Arc<String, Float>(start, end, 1.0f);
	}

	@Test
	public void testGetStartNode() {
		assertEquals(start.getItem(), arc1.getStartNode().getItem());
	}

	@Test
	public void testGetEndNode() {
		assertEquals(end.getItem(), arc1.getEndNode().getItem());
	}

	@Test
	public void testGetLabel() {
		assertEquals(1.0f, arc1.getLabel(), 0.0001f);
	}

	@Test
	public void testSwap() {
		Arc<String, Float> arc2 = new Arc<String, Float>(end, start, 1.0f);
		assertEquals(arc2.toString(), arc1.swap().toString());
	}
}
