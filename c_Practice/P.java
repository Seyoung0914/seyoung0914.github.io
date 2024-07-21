package c_Practice;

public class P {
  public static void main(String[] args) {
    int[][] numbers = {
        {10,30,80},
        {1,3,8},
        {100,200,300}
    };
    for (int x=0; x<numbers.length; x++){
      for(int i=0; i<numbers[x].length;i++){
        System.out.print(numbers[x][i]+"\t");
      }
      System.out.println();
        
    }
  }
}