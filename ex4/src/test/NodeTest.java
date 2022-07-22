//junit test

package test;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Enumeration;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import org.junit.Before;
import org.junit.Test;

import lib.*;

public class NodeTest {
	private Node<String, String> node1;
	private Node<String, String> node2;
	private Node<String, String> node3;

	@Before
	public void setUp() {
		node1 = new Node<String, String>("node1");
		node2 = new Node<String, String>("node2");
		node3 = new Node<String, String>("node3");
	}

	@Test
	public void testGetItem() {
		assertEquals("node1", node1.getItem());
	}

	@Test
	public void testAddNeighbour() {
		node1.addNeighbour(node2, "label");
		assertTrue(node1.isNeighbour(node2));
	}

	@Test
	public void testRemoveNeighbour() {
		node1.addNeighbour(node2, "label");
		node1.removeNeighbor(node2);
		assertFalse(node1.isNeighbour(node2));
	}

	@Test
	public void testGetNeighbour() {
	  boolean falg = false;
	  node1.addNeighbour(node2, "label");
	  if(node1.getNeighbour(node2).getEndNode().getItem().equals("node2")){
	    falg = true;
	  }
	  assertTrue(falg);		
	}

	@Test
	public void testGetNeighbours() {
		node1.addNeighbour(node2, "label");
		node1.addNeighbour(node3, "label");
		ArrayList<Node<String, String>> neighbours = new ArrayList<Node<String, String>>();
		ArrayList<Arc<String, String>> arcList = new ArrayList<Arc<String, String>>();
		neighbours.add(node2);
		neighbours.add(node3);
		Enumeration<Arc<String,String>> enumeration = node1.getNeighbours();
		while(enumeration.hasMoreElements()){
		  arcList.add(enumeration.nextElement());
		}
		int i = arcList.size();
		while(i > 0){
		  i--;
		  if(!neighbours.contains(arcList.get(i).getEndNode())){
		    assertTrue(false);
		  }
		}
		assertTrue(true);
	}

	@Test
	public void testNeighboursSize() {
		node1.addNeighbour(node2, "label");
		node1.addNeighbour(node3, "label");
		assertEquals(2, node1.neighboursSize());
	}

	@Test
	public void testNeighboursSizeEmpty() {
		assertEquals(0, node1.neighboursSize());
	}

	@Test
	public void testGetAdiacent(){
		node1.addNeighbour(node2, "label");
		node1.addNeighbour(node3, "label");
		Enumeration<String> nodeValue = node1.getAdiacents();
		while(nodeValue.hasMoreElements()){
		  String value = nodeValue.nextElement();
		  if(!value.equals("node2") && !value.equals("node3")){
		    assertTrue(false);
		  }
		}
		assertTrue(true);
	} 

}
