#include <stdio.h>

// ţ�ٲ�ֵ����ʽ
double newton_interpolation_value(double x[], double y[], int n, double value) {
    double result = 0.0;
    double temp[10][10];
    int i, j;

    // ��ʼ�����̱�
    for (i = 0; i < n; i++) {
        temp[i][0] = y[i];
    }

    // ���ɲ��̱�
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            temp[j][i] = (temp[j + 1][i - 1] - temp[j][i - 1]) / (x[j + i] - x[j]);
        }
    }

    // �����ֵ����ʽ��ֵ
    for (i = 0; i < n; i++) {
        double term = temp[0][i];
        for (j = 0; j < i; j++) {
            term *= (value - x[j]);
        }
        result += term;
    }

    return result;
}

// ����ţ�ٲ�ֵ����ʽϵ��
void newton_interpolation_cofficient(double x[], double y[], int n, double a[]) {
    double temp[10][10];
    int i, j;

    // ��ʼ�����̱�
    for (i = 0; i < n; i++) {
        temp[i][0] = y[i];
    }

    // ���ɲ��̱�
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            temp[j][i] = (temp[j + 1][i - 1] - temp[j][i - 1]) / (x[j + i] - x[j]);
        }
    }

    // �����ֵ����ʽ��ϵ��
    for (i = 0; i < n; i++) {
        a[i] = temp[0][i];
    }
}

int main() {
    double x[] = { 0.2, 0.4, 0.6, 0.8, 1.0 };
    double y[] = { 0.98, 0.92, 0.81, 0.64, 0.38 };
    int n = sizeof(x) / sizeof(x[0]);

    // ���ɲ�ֵ��
    double start = 0.2;
    double end = 1.0;
    double step = 0.01;

    // ��ӡ��ֵ���
    printf("x\t\tf(x)\n");
    printf("-----------------\n");
    for (double value = start; value <= end; value += step) {
        double result = newton_interpolation_value(x, y, n, value);
        printf("%.2f\t\t%.4f\n", value, result);
    }

    // �����ֵϵ��
    double a[10];
    newton_interpolation_cofficient(x, y, n, a);
    printf("ţ�ٲ�ֵ����ʽ�Ĳ�ֵϵ��:\n");
    for (int k = 0; k < n; k++) {
        printf("a_%d = %.4f\n", k, a[k]);
    }

    return 0;
}
