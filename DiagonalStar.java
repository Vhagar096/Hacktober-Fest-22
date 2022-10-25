
public class DiagonalStar {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		printSquareStar(8);

	}
    public static void printSquareStar(int number) {
        if (number < 5) {
            System.out.println("Invalid Value");
        } else {
            int column;
            for (int row = 0; row < number; row++) {
                for (column = 0; column < number; column++) {

                    if (row == 0 || row==number-1 || column==0 ||column==number-1 ||row==column || column==number-row-1)
                    {
                        System.out.print("*");
                    }
                    else {
                        System.out.print(" ");
                    }
                }
                System.out.println();

            }


        }
    }
}