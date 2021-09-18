namespace Model
{
    public static class SwapNumber 
    {
        public static void Swap(this ref int num1, ref int num2) 
        {
            if (num2 != num1)
            {
                num1 = num1 ^ num2;
                num2 = num1 ^ num2;
                num1 = num1 ^ num2;
            }
        }
    }
}
