package test;

import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

import lib.*;

public class TestRun{
  public static void main(String[] args) {
    Result nodeResult = JUnitCore.runClasses(NodeTest.class);
    for (Failure failure : nodeResult.getFailures()) {
      System.out.println(failure.toString());
    }
    System.out.println("Node test passed: " + nodeResult.wasSuccessful());

    Result arcResult = JUnitCore.runClasses(ArcTest.class);
    for (Failure failure : arcResult.getFailures()) {
      System.out.println(failure.toString());
    }
    System.out.println("Arc test passed: " + arcResult.wasSuccessful());


    Result graphResult = JUnitCore.runClasses(GraphTest.class);
    for (Failure failure : graphResult.getFailures()) {
      System.out.println(failure.toString());
    }
    System.out.println("Graph test passed: " + graphResult.wasSuccessful());
  }
}