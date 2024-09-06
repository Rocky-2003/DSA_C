public class Index {
  public void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {

    if (n == 0) {
      return;
    }
    //This will move from A to b
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    //This will move from A to C
    System.out.println("Disk " + n + " from_rod " + fromRod + " to_rod " + toRod);
    //This will move from b  to C
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);

  }

  public static void main(String arg[]) {
    Index p = new Index();
    p.towerOfHanoi(3, 'A', 'C', 'B');

  }
}