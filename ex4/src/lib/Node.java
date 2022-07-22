package lib;

import java.util.Hashtable;
import java.util.ArrayList;
import java.util.Enumeration;

public class Node<T,L> {
private T item;
private Hashtable<T,Arc<T,L>> neighbours;

  //constructor generic
  public Node(T value) {
    this.item = value;
    this.neighbours = new Hashtable<T,Arc<T,L>>();
  }

  /**
   * Getter for item
   * @return item
   */
  public T getItem() {
    return item;
  }

  /**
   * save Neighbour and relativ arc
   * @param thisNode
   * @param neighbour
   * @param label
   */
  public void addNeighbour(Node<T,L> arrival, L label) {
    this.neighbours.put(arrival.getItem(),new Arc<>(this,arrival,label));
  }

  /**
   * Remove a neighbour
   * @param neighbour
   */
  public void removeNeighbor(Node<T,L> arrival) throws IllegalArgumentException {
    if(this.isNeighbour(arrival)){
      this.neighbours.remove(arrival.getItem());
    }
    else{
      throw new IllegalArgumentException("Arc remove on non existing arrival node");
    }
  }

  /**
   * Check if a neighbour exist
   * @param neighbour
   * @return boolean
   */
  public boolean isNeighbour(Node<T,L> arrival){
    return this.neighbours.containsKey(arrival.getItem());
  }

  /**
   * Getter the arc for a neighbours
   * @return Arc
   */
  public Arc<T,L> getNeighbour(Node<T,L> arrival)throws IllegalArgumentException{
    if(this.isNeighbour(arrival)){
      return this.neighbours.get(arrival.getItem());
    }
    else{
      throw new IllegalArgumentException("Get Arc on non existing arrival node");
    }
  }

  /**
   * Get total number of neighbours
   * @return neighboursNumber
   */
  public int neighboursSize(){
    return this.neighbours.size();
  }

  /**
   * Implementesion of the Enumeration interface for the neighbours
   * @return Node
   */
  public Enumeration<Arc<T,L>> getNeighbours(){
    return this.neighbours.elements();
  }
  
  /**
   * Getter for neighboursList
   * @return
   */
  public Enumeration<T> getAdiacents(){
    return this.neighbours.keys();
  }
}
