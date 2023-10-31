class BoxingAndUnboxing{
    @SuppressWarnings("removal")
    public static void main(String[] args){
        // Boxing -> setting the value of a primitive datatype into an instance of it's wrapper class.
        int i = 100;
        Integer I = new Integer(i);
        System.out.println("int : " + i);
        System.out.println("[Boxing] int -> Integer : " + I);

        // Unboxing -> setting the value of an instance of any wrapper class into it's respective primitive datatype.
        Character CH = new Character('x');
        char ch = CH;
        System.out.println("Character : " + CH);
        System.out.println("[Unboxing] Character -> char : " + ch);
    }
}
