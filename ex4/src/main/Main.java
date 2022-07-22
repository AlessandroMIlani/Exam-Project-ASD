package main;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Hashtable;
import java.util.Enumeration;

import lib.*;
import minheap.*;

public class Main {
	public static void main(String[] args) {
		// check arg[1] not null
		if (args[0] == null)
			throw new IllegalArgumentException("arg[1] can't be null");
		UndirectedGraph<String, Float> g = new UndirectedGraph<String, Float>();

		// read csv file from argument
		String csvFile = args[0];
		try {
			BufferedReader br = new BufferedReader(new FileReader(csvFile));
			String line = br.readLine();
			while (line != null) {
				String[] node = line.split(",");
				g.addNode(node[0]);
				g.addNode(node[1]);
				// string to float
				Float f = Float.parseFloat(node[2]);
				g.addArc(node[0], node[1], f);
				line = br.readLine();
			}
			br.close();

		} catch (IOException e) {
			throw new RuntimeException(e);
		}

		// use of Dijkstra
		Dijkstra(g, "torino", "catania");
	}

	/**
	 * Implementation of Dijkstra algorithm
	 * 
	 * @param g     graph
	 * @param start start node
	 * @param end   end node
	 */
	public static void Dijkstra(Graph<String, Float> g, String start, String end) {
		ArrayList<Node<String, Float>> arr = g.getNodes();
		ArrayList<Cnode> cList = new ArrayList<>();
		Hashtable<String, Cnode> ht = new Hashtable<>();

		MinHeap<Cnode> heap = new MinHeap<>(new Comparator<Cnode>() {
			@Override
			public int compare(Cnode o1, Cnode o2) {
				return o1.getDist().compareTo(o2.getDist());
			}
		});

		for (Node<String, Float> node : arr) {
			if (node.getItem().equals(start)) {
				Cnode cnode = new Cnode(node, 0f, null);
				heap.insert(cnode);
				cList.add(cnode);
				ht.put(node.getItem(), cnode);
			} 
			else{
				Cnode cnode = new Cnode(node,Float.MAX_VALUE, null);
				heap.insert(cnode);
				cList.add(cnode);
				ht.put(node.getItem(), cnode);
			}
		}

	while(!heap.isEmpty()){
      Cnode cnode = heap.remove();
      Enumeration<Arc<String,Float>> en=cnode.getArrival().getNeighbours();
      while(en.hasMoreElements()){
        Arc<String, Float> arc = en.nextElement();
        float newDist = cnode.getDist() + arc.getLabel();
        String key = arc.getEndNode().getItem();
        if(newDist < ht.get(key).getDist()){
          Cnode newCnode = new Cnode(arc.getEndNode(), newDist, arc.getStartNode());
          heap.decrease(ht.get(key), newCnode);
          ht.put(key, newCnode);
        }
      }
    }
		// print dist end
		System.out.println("Shortest path to "+ end+":"+ ht.get(end).getDist());
		// print path
		ArrayList<String> path = new ArrayList<>();
		Cnode cnode = ht.get(end);
		while (cnode.getParent() != null) {
			path.add(cnode.getArrival().getItem());
			cnode = ht.get(cnode.getParent().getItem());
		}
		System.out.println("percorso completo da Torino alla destinazione: \n");
		for (int i = path.size() - 1; i >= 0; i--) {
			System.out.print(path.get(i) + " ");
			if (i != 0)
				System.out.print("--> ");
		}
		System.out.println();

	}
}