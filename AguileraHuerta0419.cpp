    #include <iostream>
    #include <math.h>
    using namespace std;


    //Functions prototypes
    int SizeArray(int &sizeArray);
    float *CreateArray(int size);
    int SetValues(float* data, int size, float value);
    float Average(float* p, int& sizeArray);
    int syArregloCaptura(float x[], int nD);
    int DataInput(float data[], int size);    
    int PrintData(float& average, float& variance, float& standarDeviation, int& mode, float& asymmetry, float& curtosisRes);
    int DestroyArray(float* p);

    //Functions prototypes for calculating statistical data
    float Variance(float& average, int& sizeArray, float* data);
    float StandarDeviation(float& var);
    int Mode(float* data, int& sizeArray);
    float MomentOfAsymmetry(float& average, int& mode, float& standarDeviation);
    float Curtosis(float& average, float&standarDeviation, int& sizeArray, float* data);

    int main ()
    {
        int sizeArray;
        cout << "Program to calculate statistical data with an array" << endl;
        sizeArray = SizeArray(sizeArray);
        float* data = CreateArray(sizeArray);
        SetValues(data, sizeArray, 0);
        DataInput(data, sizeArray);
        float average = Average(data, sizeArray);
        float var = Variance(average, sizeArray, data);
        float standarDeviation = StandarDeviation(var);
        int mode = Mode(data, sizeArray);
        float asymmetry = MomentOfAsymmetry(average, mode, standarDeviation);
        float curtosisRes = Curtosis(average, standarDeviation, sizeArray, data);
        PrintData(average, var, standarDeviation, mode, asymmetry, curtosisRes);

        DestroyArray(data);
    }

    int SizeArray(int &sizeArray){
    do
        {
        cout << "Enter the total amount of data you will enter: ";
        cin >> sizeArray;
        } while (sizeArray < 1);
        return sizeArray;
    }

    float* CreateArray(int size)
    {
        float *p = new float[size];
        if(!p)
        {
        cout << "\nMemory allocation error.\n";
        return NULL;
        }
        return p;
    }

    int SetValues(float* data, int size, float value)
    {
        for (int k = 0; k < size; k++)
        {
            data[k] = value;
        }
    return 0;
    }
    
    int DataInput(float data[], int size)
    {
    cout<<"Data capture" << endl;
    for (int k = 0; k < size; k++)
    {
        cout <<"Data " << k+1 <<" : ";
        cin >> data[k];
    }
    cout << "\n\n";
    
    return 0;
    }

    int PrintData(float& average, float& variance, float& standarDeviation, int& mode, float& asymmetry, float& curtosisRes)
    {
        cout << "The total average is: " << average << "\n";
        cout << "The variance is: " << variance << "\n";
        cout << "The standar deviation is: " << standarDeviation << "\n";
        cout << "The mode is: " << mode << "\n";
        cout << "The Asymmetry is: " << asymmetry << "\n";
        cout << "The The curtousis is: " << curtosisRes << "\n";
        system("pause");
        /* 
        No pude usar otra función como cin.get o cin.ignore, no sé porque no
        esperaban a que el usuario terminara la ejecución, la única que funcionó fue la de system("pause"),
        pero esa imprime el mensaje el español, no sé si usted sepa porque pasa eso profesor
        */
        return 0;
    }

    int DestroyArray(float* data)
    {
        if(data)
        {
        delete[]data;
        }
    else 
    {
        cout << "\n\nNo memory allocated\n\n";
    }
        return 0;
    }
    
    //Functions for calculating statistical data
    float Average(float* data, int& sizeArray)
    {
        float average;
        for (int k = 0; k < sizeArray; k++)
        {
            average += data[k];
        }
        return average = average/sizeArray;
    }

    float Variance(float& average, int& sizeArray, float* data)
    {
        float variance = 0;
        for (size_t k = 0; k < sizeArray; k++)
        {
            variance += pow((data[k] - average), 2);
        }
        variance = variance / sizeArray;
        return variance;
    }

    float MomentOfAsymmetry(float& average, int& mode, float& standarDeviation)
    {
        float Asymmetry = (average - mode) / standarDeviation;

        return Asymmetry;
    }

    float StandarDeviation(float& var)
    {
        float sDeviation = sqrt(var);
        return sDeviation;
    }

    int Mode(float* data, int& sizeArray)
    {
        int element = 0;
        int count = 0;

        for (size_t i = 0; i < sizeArray; i++)
        {
            int tempElement = data[i];
            int tempCount = 0;
            for (size_t ib = 0; ib < sizeArray; ib++)
            {
                if (data[ib] == tempElement)
                {
                    tempCount++;
                }
            }
                if (tempCount > count)
                {
                    element = tempElement;
                    count = tempCount;
                }
        }
        return element;
    }

    float Curtosis(float& average, float&standarDeviation, int& sizeArray, float* data)
    {
        unsigned int total;
        unsigned int fourMoment;
        float curtosisResult;
        for (size_t i = 0; i < sizeArray; i++)
        {
            total += pow((data[i] - average),4);
        }
        fourMoment = total/sizeArray;

        curtosisResult = (fourMoment/pow(standarDeviation,4))-3;
        return curtosisResult;
    }
