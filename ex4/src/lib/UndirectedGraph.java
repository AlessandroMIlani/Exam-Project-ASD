package lib;

public class UndirectedGraph<T, L> extends Graph<T, L> {

  /**
   * Constructor for UndirectedGraph
   */
  public UndirectedGraph() {
      super();
  }

  /**
   * Add an arc to the graph
   * 
   * @param start
   * @param end
   * @param label
   */
  @Override
  public void addArc(T start, T arrival, L label) {
    super.addArc(start, arrival, label);
    super.addArc(arrival, start, label);
  }

  /**
   * remove an arc from the graph
   * 
   * @param start
   * @param end
   */
  @Override
  public void removeArc(T start, T arrival) {
    super.removeArc(start, arrival);
    super.removeArc(arrival, start);
  }

  /**
   * check if the graph is directed
   * 
   * @return boolean
   */
  @Override
  public boolean checkDirection() {
    return false;
  }
}
