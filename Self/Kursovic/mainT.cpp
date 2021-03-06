#include <iostream>
float diff(float *fucFi, float *difference, float *y){
    float result = 0;
    for(int i = 0; i  < LENGTH; i++){
        difference[i] = fucFi[i] - y[i];
        result += difference[i];
    }
    return result;
}
float fi(float *fucFi, float *x, float &C1, float &C2, float &C3){
    float result = 0;
    for(int i = 0; i < LENGTH; i++){
        fucFi[i] = C1 + 2 * C2 * x[i] + (4 * x[i] * x[i] - 2) * C3;
        result += fucFi[i];
    }
    return result;
}
float sq(float *difference, float *sqare){
    float result = 0;
    for(int i = 0; i < LENGTH; i++){
        sqare[i] = difference[i] * difference[i];
        result += sqare[i];
    }
    return result;
}
void zedelMethod(float *matrix, float accuracy, float &C1 ,float &C2 ,float &C3){
    float tmp1, tmp2, tmp3;
    /*float tmp1 = 0;
    float tmp[3];
    float arr[] = {C1, C2, C3};*/
        do{
        /*tmp1 = 0;
        for( int i = 0; i < WIDTH*3;i += 4){
            tmp[i/4] = arr[i/4];
                for(int j = 0; j < WIDTH; j++)
                    switch(i+j){
                        case i+WIDTH :
                            arr[i/4] += matrix[i+j];
                            break;
                        case !(i/4 == j):
                            arr[i/4] += matrix[i + j] * C[j];
                            break;
                        default:
                            break;
                    }
                arr[i/4] /= matrix[i + i/4];
                tmp1 += abs(abs(tmp[i/4]) - abs(arr[i/4]));
        }*/
            tmp1 = C1; tmp2 = C2; tmp3 = C3;
            C1 = (matrix[3] - matrix[1] * C2 - matrix[2] * C3) / matrix[0];     // 0 1 2 3
            C2 = (matrix[7] - matrix[4] * C1 - matrix[6] * C3) / matrix[5];     // 4 5 6 7
            C3 = (matrix[11] - matrix[8] * C1 - matrix[9] * C2) / matrix[10];   // 8 9 10 11*/
        }while((abs(tmp1 - C1) >= accuracy) &&
                 (abs(tmp2 - C2) >= accuracy) &&
                 (abs(tmp3 - C3) >= accuracy));
    /*}while(tmp1 >= accuracy);
    C1 = arr[0]; C2 = arr[1]; C3 = arr[2];*/
}
void coeff(float *x,float *y, float *matrix){
    for( int i = 0; i < WIDTH*3;i += 4){
            for(int j = 0; j < WIDTH-1; j++){                       // 0 1 2 3
                matrix[i + j] = 0;                                  // 4 5 6 7
                for(int k = 0; k < LENGTH;k++)                      // 8 9 10 11
                    matrix[i + j] += fi(x[k], i / 4) * fi(x[k], j);
            }
            matrix[i + WIDTH]=0;
            for(int k = 0;k < LENGTH; k++)
                matrix[i + 3] += y[k] * fi(x[k],i / 4);
        }
}
void split(std::string string, float *array){
    std::string tmp = string.split(' ');
    for(int i = 0; i < LENGTH; i++)
        array[i] = tmp.at(i).toFloat();
}
void stringMatrix(float *matrix){
    output = "";
    for(int start = 0; start < WIDTH*3; start += 4){
            for( int i = start; i < start + 4; i++)
                output += QString::number(transform(matrix[i])) + "\t";
            output += "\n";
    }
}
void mainWork();//yes
float abs(float x){
    if(x < 0)
        x = -1 * x;
    return x;
}
float transform(float &a){
    int b = a * 1000;
    a = (float) b / 1000;
    return a;
}
float fi(float x,int i){
    switch(i){
        case 0 :
            return 1;
        case 1:
            return 2 * x;
        default :
            return 4 * x * x - 2;
    }
}

bool convergence(float *matrix){
    for( int i = 0; i < WIDTH*3;i += 4){
        float tmp = 0, tmp2;
        for(int j = 0; j < WIDTH-1; j++)
            if(i/4 != j)
                tmp += abs(matrix[i + j]);
            else
                tmp2 = abs(matrix[i + j]);
        if(tmp >= tmp2)
            return false;
    }
    return true;
}
std::string output;
float unsver;
float C1 = 0, C2 = 0, C3 = 0;
float arrayOfX[LENGTH], arrayOfY[LENGTH], matrix[3*4], X, Y, accuracy;
float funcFi[LENGTH], difference[LENGTH], sqare[LENGTH];

int main(){

    coeff(arrayOfX, arrayOfY, matrix);
    stringMatrix(matrix);
    if(!convergence(matrix)){
        std::cout << "No convergence" << std::endl;
        return;
    }
    zedelMethod(matrix , accuracy, C1, C2, C3);
    fi(funcFi, arrayOfX, C1, C2, C3);
    diff(funcFi, difference, arrayOfY);
    unsver = sq(difference, sqare);
    output += "Unswer is : ";
     bv ;
    std::cout << output << std::endl;
    return 0;
}