package lib;

import java.util.Hashtable;
import java.util.ArrayList;
import java.util.Enumeration;

/**
 * Graph
 */
public class Graph<T,L> {
  private Hashtable<T,Node<T,L>> table;

  public Graph() {
    this.table=new Hashtable<>();
  }

  /**
   * Add a node to the graph
   * @param value
   */
  public void addNode(T item) {
    //check if already exists
    if(!this.table.containsKey(item)){
      this.table.put(item,new Node<>(item));
    }
  }

  /**
   * remove a node from the graph
   * @param value
   */
  public void removeNode(T item) throws IllegalArgumentException {
    if(table.containsKey(item)){
      ArrayList<Node<T,L>> arr=getNodes();
        for(Node<T,L> i : arr){
            if (isArc(i.getItem(), item)){
                removeArc(i.getItem(), item);
            }
        }
      table.remove(item);
    }
    else{
      throw new IllegalArgumentException("Remove on non existing node");
    }
  }

  /**
   * Add an arc to the graph
   * @param start
   * @param end
   * @param label
   */
  public void addArc(T start,T arrival, L label) throws IllegalArgumentException{
    if(table.containsKey(start) && table.containsKey(arrival)){
      table.get(start).addNeighbour(table.get(arrival), label);
    }
    else{
      throw new IllegalArgumentException("Arc add on non existing nodes");
    }
  }
  
  /**
   * Remove an arc from the graph
   * @param start
   * @param end
   */
  public void removeArc(T start, T arrival) throws IllegalArgumentException{
    if(table.containsKey(start) && table.containsKey(arrival)){
      table.get(start).removeNeighbor(table.get(arrival));
    }
    else{
      throw new IllegalArgumentException("Arc add on non existing nodes");
    }
  }
  
  /**
   * check if a node is in the graph
   * @param value
   */
  public boolean isNode(T node) {
    return table.containsKey(node);
  }

  /**
   * check if an arc is in the graph
   * @param start
   * @param end
   */
  public boolean isArc(T start, T arrival) {
    return table.get(start).isNeighbour(table.get(arrival));
  }

  /**
   * get the nodes of the graph
   * @return ArrayList<Node<T,L>>
   */
  public int nodesNum(){
    return table.size();
  }

  /**
   * get the arcs of the graph
   * @return ArrayList<Arc<T,L>>
   */
  public int archNum(){
    int total=0;
    Enumeration<Node<T,L>> en=table.elements();
    while(en.hasMoreElements()){
      total+=en.nextElement().neighboursSize();
    }
    return total;
  }

  /**
   * get the nodes of the graph
   * @return ArrayList<Node<T,L>>
   */
  public ArrayList<Node<T,L>> getNodes(){
    ArrayList<Node<T,L>> res=new ArrayList<>();
    Enumeration<Node<T,L>> en=table.elements();
    while(en.hasMoreElements()){
      res.add(en.nextElement());
    }
    return res;
  }

  /**
   * get the arcs of the graph
   * @return ArrayList<Arc<T,L>>
   */
  public  ArrayList<Arc<T,L>> getArches(){
    ArrayList<Arc<T,L>> res=new ArrayList<>();
    Enumeration<Node<T,L>> en=table.elements();
    while(en.hasMoreElements()){
      Enumeration<Arc<T,L>> en2=en.nextElement().getNeighbours();
      while(en2.hasMoreElements()){
        res.add(en2.nextElement());
      }
    }
    return res;
  }

  /**
   * get the label of an arc
   * @param start
   * @param end
   * @return label
   */
  public L getLabel(T startNode,T endNode) throws IllegalArgumentException{
    if(table.containsKey(startNode) && table.get(startNode).isNeighbour(table.get(endNode))){
      return table.get(startNode).getNeighbour(table.get(endNode)).getLabel();
    }
    else{
      throw new IllegalArgumentException("GetLabel on non existing start node");
    }

  }

  /**
   * check if the graph is Directed
   * @return boolean
   */
  public boolean checkDirection(){
    return true;
  }
}