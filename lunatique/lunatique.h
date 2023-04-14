// Développé par Benstitou Sofiane
// -------- START Basics ----------
double lunabs(double x){
    if (x < 0){
        return (-1 * x);
    }
    else{
        return x;
    }
}

long long int limfactorial(int n){ // limited to 20!
    if (n < 0 || n > 20){
        return 0;
    } else if (n == 0){
        return 1;
    } else {
        return n*limfactorial(n-1);
    }
}

double powern(double x, int n){
    double result = 1.0;
    if (n < 0){
        return 1/(powern(x, lunabs(n)));
    } else{
        for (int i = 0; i < n; i++){
            result *= x;
        }
        return result;
    }
}

double powerab(double x, int a, int b){ // Using Newton method : https://www.youtube.com/watch?v=Z_BDJaveZNs&t=337s
    if (a/b < 0){
        a = -1 * lunabs(a);
        b = lunabs(b);
    } else if (a < 0 && b < 0){
        a = lunabs(a);
        b = lunabs(b);
    } 
    double result = 4.0;
    double y = powern(result,b) - x;
    double yp = b*powern(result,b-1);
    if (a == 1) {
        for (int i = 0; i < 10; i++){
            result -= y/yp;
            y = powern(result,b) - x;
            yp = b*powern(result,b-1);
        }
        return result;
    
    } else if (a > 0 || a < 0){
        for (int i = 0; i < 10; i++){
            result -= y/yp;
            y = powern(result,b) - x;
            yp = b*powern(result,b-1);
        }
        return powern(result,a);
    } else if (a == 0){
        return 1;
    }
}
// ----------- END Basics -------------

// --------- START USUAL ----------

double inverse(double x){
    return 1/x;
}

double sqrt(double x){
    return powerab(x,1,2);
}

double sq(double x){
    return x*x;
}

// ----- END USUAL ------

// ----- START CONST ----- 

double exp(double x){ // https://fr.wikipedia.org/wiki/Factorielle
    double result = 0; 
    for (int i = 0; i < 20; i++){
        result += powern(x,i)/limfactorial(i);
    }
}

double picalc(int p){ //https://fr.wikipedia.org/wiki/Pi
    double result = 1;
    for (int i = 1; i < p+1; i++){
        result *= sq(2*i)/(sq(2*i) - 1);
    }
    return 2*result;
}

// ----- END CONST ------

// ----- START TRIGONOMETRIC -----

double sin(double x){ // https://fr.wikipedia.org/wiki/Fonction_trigonom%C3%A9trique
    double result = 0; 
    for (int i = 0; i < 20 ; i++){
        result += powern(x,i+1)/limfactorial(2*i + 1);
    }
    return result;
}

double cos(double x){
    double result = 0; 
    for (int i = 0; i < 20 ; i++){
        result += powern(x,i)/limfactorial(2*i);
    }
    return result;
}

double tan(double x){
    return sin(x)/cos(x);
}

// ----- END TRIGONOMETRIC -----

//Make sigma and pi function ! (sum and prod)