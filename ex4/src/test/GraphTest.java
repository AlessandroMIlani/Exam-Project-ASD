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

/**
 * LibTest
 */
public class GraphTest {

	private Graph<String, Float> graph;

	@Before
	public void CreateGraph() {
		graph = new Graph<>();
	}

	@Test
	public void testAddNodeAndIsNode() {
		graph.addNode("A");
		assertTrue(graph.isNode("A"));
	}

	@Test
	public void testRemoveNode() {
		graph.addNode("A");
		graph.removeNode("A");
		assertFalse(graph.isNode("A"));
	}

	@Test
	public void testAddArcAndIsArc() {
		graph.addNode("A");
		graph.addNode("B");
		graph.addArc("A", "B", 1.0f);
		assertTrue(graph.isArc("A", "B"));
	}

	@Test
	public void testRemoveArc() {
		graph.addNode("A");
		graph.addNode("B");
		graph.addArc("A", "B", 1.0f);
		graph.removeArc("A", "B");
		assertFalse(graph.isArc("A", "B"));
	}

	@Test
	public void testNodesNum() {
		graph.addNode("A");
		graph.addNode("B");
		assertEquals(2, graph.nodesNum());
	}

	@Test
	public void testArcsNum() {
		graph.addNode("A");
		graph.addNode("B");
		graph.addArc("A", "B", 1.0f);
		assertEquals(1, graph.archNum());
	}

	@Test
	public void testGetNodes() {
		boolean flag = true;
		ArrayList<Node<String, Float>> nodes = new ArrayList<>();
		nodes.add(new Node<>("A"));
		nodes.add(new Node<>("B"));
		graph.addNode("A");
		graph.addNode("B");
		for(int i=0; i<nodes.size();i++){
			if(!(nodes.get(i).getItem().equals(graph.getNodes().get(i).getItem())))
				flag = false;
		}
		assertTrue(flag);
	}

	@Test
	public void testGetArcs() {
		ArrayList<Arc<String, Float>> arcs = new ArrayList<>();
		Node<String, Float> start = new Node<>("A");
		Node<String,Float> end = new Node<>("B");
		arcs.add(new Arc<String, Float>(start, end, 1.0f));
		graph.addNode("A");
		graph.addNode("B");
		graph.addArc("A", "B", 1.0f);
		assertEquals(arcs.toString(), graph.getArches().toString());
	}

	@Test
	public void testGetLabel() {
		graph.addNode("A");
		graph.addNode("B");
		graph.addArc("A", "B", 1.0f);
		assertEquals(1.0f, graph.getLabel("A", "B"), 0.001f);
	}

	@Test
	public void testCheckDirection() {
		assertTrue(graph.checkDirection());
	}
}