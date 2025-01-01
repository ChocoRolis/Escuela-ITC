unsigned long int string_a_int(string num){
    
        unsigned long int ValorInt = 0, temp = 1;

        for (int i = 0; i < num.size(); i++)
        {
                for (int a = i+1; a < num.size(); a++)
                {
                        temp = temp * 10;
                }

                ValorInt += ((unsigned long int) num[i] - 48) * temp;
                temp = 1;
        }

        return ValorInt;
}
