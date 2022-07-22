package lib;

public class Arc<T,L> {
  private Node<T,L> startNode;
  private Node<T,L> endNode;
  private L label;

  /**
   * Constructor for Arc
   * @param startNode
   * @param endNode
   * @param label
   */
  public Arc(Node<T,L> startNode, Node<T,L> endNode, L label) {
    this.startNode = startNode;
    this.endNode = endNode;
    this.label = label;
  }

  /**
   * Getter for startNode
   * @return startNode
   */
   
  public Node<T,L> getStartNode() {
    return startNode;
  }

  /**
   * Getter for endNode
   * @return endNode
   */
  public Node<T,L> getEndNode() {
    return endNode;
  }

  /**
   * Getter for label
   * @return label
   */
  public L getLabel(){
    return label;
  }

  /**
   * Swap startNode and endNode
   * @return Arc
   */
  public Arc<T,L> swap(){
    return new Arc<T,L>(endNode, startNode, label);
  }

  /**
   * Return Arc like a string
   * @return String
   */
  public String toString(){
    return startNode.getItem() + " -> " + endNode.getItem() + " : " + label;
  }
}
