// power functions
double powern(double x, int n){
    double result = 1.0;
    
    for (int i = 0; i < n ; i++){
        result *= x;
    }

    return result;
}