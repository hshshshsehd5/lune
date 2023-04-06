double powern(double x, int n){
    double result = 1.0;
    for (int i = 0; i < n; i++){
        result *= x;
    }
    return result;
}

double powerab(double x, int a, int b){ // Using Newton method : https://www.youtube.com/watch?v=Z_BDJaveZNs&t=337s
    double result = 4.0;
    double y = powern(result,b) - x;
    double yp = b*powern(result,b-1);

    if (a > 0){
        for (int i = 0; i < 10; i++){
            result -= y/yp;
            y = powern(result,b) - x;
            yp = b*powern(result,b-1);
        }
    return powern(result,a);
    } else {
        for (int i = 0; i < 10; i++){
            result -= y/yp;
            y = powern(result,b) - x;
            yp = b*powern(result,b-1);
        }

        return result;
    }

    
}
