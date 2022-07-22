package main;

import lib.Node;

/**
 * Wrapper class for use node in the Dijkstra algorithm
 */
public class Cnode {

	private Node<String, Float> arrival;
	private Node<String, Float> parent;
	private Float dist;

	/**
	 * Constructor for Cnode
	 * 
	 * @param arrival this node
	 * @param parent  parent node
	 * @param dist    label of the arc
	 */
	public Cnode(Node<String, Float> arrival, float dist, Node<String, Float> parent) {
		this.arrival = arrival;
		this.dist = dist;
		this.parent = parent;
	}

	/**
	 * Getter for arrival
	 * 
	 * @return arrival
	 */
	public Node<String, Float> getArrival() {
		return arrival;
	}

	/**
	 * Getter for parent
	 * 
	 * @return parent
	 */
	public Node<String, Float> getParent() {
		return parent;
	}

	/**
	 * Getter for dist
	 * 
	 * @return dist
	 */
	public Float getDist() {
		return dist;
	}

	/**
	 * Setter for dist
	 * 
	 * @param dist
	 */
	public void editDist(Float dist) {
		this.dist = dist;
	}

	/**
	 * Setter for parent
	 * 
	 * @param parent
	 */
	public void editParent(Node<String, Float> parent) {
		this.parent = parent;
	}
}
