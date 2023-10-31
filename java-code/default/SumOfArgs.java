public class SumOfArgs {
    public static void main(String[] args) {
        if(args.length == 0){
            System.out.println("No Input args found");
            return;
        }
            int sum = 0;
            for (String e : args )
                sum += Integer.parseInt(e);
            System.out.println("Sum = " + sum);
    }
}
