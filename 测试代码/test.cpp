#define _CRT_SECURE_NO_DEPRECATE

//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class SquareMatrix {
//private:
//    int size;
//    int* data;
//
//public:
//    SquareMatrix(int s) : size(s) {
//        data = new int[size * size];
//        memset(data, 0, size * size * sizeof(int));
//    }
//
//    SquareMatrix(const SquareMatrix& other) : size(other.size) {
//        data = new int[size * size];
//        memcpy(data, other.data, size * size * sizeof(int));
//        cout << "Copy Successfully!" << endl;
//    }
//
//    ~SquareMatrix() {
//        delete[] data;
//        cout << "Call Destructor" << endl;
//    }
//
//    void scan(int* arr, int len) {
//        int i = 0, j = 0, k = 0;
//        while (k < len && i < size && j < size) {
//            data[i * size + j] = arr[k];
//            if ((i + j) % 2 == 0) {
//                if (j == size - 1) {
//                    i++;
//                }
//                else if (i == 0) {
//                    j++;
//                }
//                else {
//                    i--;
//                    j++;
//                }
//            }
//            else {
//                if (i == size - 1) {
//                    j++;
//                }
//                else if (j == 0) {
//                    i++;
//                }
//                else {
//                    i++;
//                    j--;
//                }
//            }
//            k++;
//        }
//    }
//
//    void print() const {
//        for (int i = 0; i < size; i++) {
//            for (int j = 0; j < size; j++) {
//                cout << data[i * size + j];
//                if (j < size - 1) {
//                    cout << " ";
//                }
//            }
//            cout << endl;
//        }
//    }
//};
//
//int main() {
//    int m, n;
//    cin >> m >> n;
//
//    int* arr = new int[m];
//    for (int i = 0; i < m; i++) {
//        cin >> arr[i];
//    }
//
//    SquareMatrix p1(n);
//    p1.scan(arr, m);
//    p1.print();
//
//    SquareMatrix p2 = p1;
//    p2.print();
//
//    delete[] arr;
//    return 0;
//}

//#include <iostream>
//#include <fstream>
//using namespace std;
//
//class Matrix {
//private:
//    int m, n; //����ά�ȣ�m�У�n�У�
//    int** pr; //�����ά����ָ��
//public:
//    //Matrix() { m = 0, n = 0; }
//    Matrix(int m1, int n1)
//    {
//        m = m1;
//        n = n1;
//        pr = new int* [m];
//        for (int k = 0; k < m; k++)
//        {
//            pr[k] = new int[n];
//        }
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                pr[i][j] = 0;
//            }
//        }
//    }; //���캯��������ʼ��m��n�е�����Ϊint�Ķ�ά���飬����Ԫ�ؾ�Ϊ0
//    Matrix(Matrix& other)
//    {
//        m = other.m;
//        n = other.n;
//        pr = new int* [m];
//        for (int k = 0; k < m; k++)
//        {
//            pr[k] = new int[n];
//        }
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                pr[i][j] = other.pr[i][j];
//            }
//        }
//    }; //���ƹ��캯����ע��ʵ�����
//    ~Matrix()
//    {
//        for (int i = 0; i < m; i++)
//        {
//            delete[] pr[i];
//        }
//        delete[] pr;
//    }; //�����������ͷŶ�ά����ռ�
//
//    void setValue(int i, int j, int v)
//    {
//        pr[i][j] = v;
//    }; //�������i�е�j��Ԫ�ظ�ֵΪv
//    Matrix operator + (Matrix& other)
//    {
//        //������������ά���Ƿ����
//        if (m != other.m || n != other.n) {
//            return *this;
//        }
//
//        //�����µľ��󲢳�ʼ��Ԫ��Ϊ0
//        Matrix result(m, n);
//
//        //���о���ӷ�
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                result.pr[i][j] = pr[i][j] + other.pr[i][j];
//            }
//        }
//
//        int i, j;
//        for (i = 0; i < m; i++) {
//            for (j = 0; j < n - 1; j++) {
//                cout << result.pr[i][j] << " ";
//            }
//            cout << result.pr[i][n - 1];
//            cout << endl;
//        }
//
//        return result;
//    }; //����ӷ�    
//    Matrix operator - (Matrix& other)
//    {
//        //������������ά���Ƿ����
//        if (m != other.m || n != other.n) {
//            return *this;
//        }
//        //�����µľ��󲢳�ʼ��Ԫ��Ϊ0
//        Matrix result(m, n);
//
//        //���о������
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                result.pr[i][j] = pr[i][j] - other.pr[i][j];
//            }
//        }
//
//        int i, j;
//        for (i = 0; i < m; i++) {
//            for (j = 0; j < n - 1; j++) {
//                cout << result.pr[i][j] << " ";
//            }
//            cout << result.pr[i][n - 1];
//            cout << endl;
//        }
//
//        return result;
//    }; //�������
//    Matrix operator * (Matrix& other)
//    {
//        //������������ά���Ƿ��������˷�������
//        if (n != other.m) {
//            return *this;
//        }
//        //�����µľ��󲢳�ʼ��Ԫ��Ϊ0
//        Matrix result(m, other.n);
//
//        //���о���˷�
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < other.n; j++) {
//                for (int k = 0; k < n; k++) {
//                    result.pr[i][j] += pr[i][k] * other.pr[k][j];
//                }
//            }
//        }
//
//        int i, j;
//        for (i = 0; i < m; i++) {
//            for (j = 0; j < other.n - 1; j++) {
//                cout << result.pr[i][j] << " ";
//            }
//            cout << result.pr[i][other.n - 1];
//            cout << endl;
//        }
//
//        return result;
//    }; //����˷���ע�ⲻ��Ԫ�ؼ����  
//    Matrix transpose()
//    {
//        //�����µľ��󲢳�ʼ��Ԫ��Ϊ0
//        Matrix result(n, m);
//        //���о���ת��
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                result.pr[j][i] = pr[i][j];
//            }
//        }
//
//        int i, j;
//        for (i = 0; i < n; i++) {
//            for (j = 0; j < m - 1; j++) {
//                cout << result.pr[i][j] << " ";
//            }
//            cout << result.pr[i][m - 1];
//            cout << endl;
//        }
//
//        return result;
//    }; //����ת�ã�ע�Ᵽ��ԭ���󲻱䣬���µ�ת�þ��󷵻�
//    friend ostream& operator<<(ostream&, Matrix&);
//    friend istream& operator>>(istream&, Matrix&);
//    /*void show(ostream&) //�������
//    {
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                cout << pr[i][j] << " ";
//            }
//            cout << endl;
//        }
//    };*/
//};
//ostream& operator<<(ostream& output, Matrix& r)
//{
//    for (int i = 0; i < r.m; i++)
//    {
//        for (int j = 0; j < r.n; j++)
//            output << r.pr[i][j] << " ";
//        output << endl;
//    }
//    return output;
//};
//istream& operator>>(istream& input, Matrix& r)
//{
//    for (int i = 0; i < r.m; i++)
//    {
//        for (int j = 0; j < r.n; j++)
//            input >> r.pr[i][j];
//    }
//    return input;
//};
//int main()
//{
//    int m1, n1, m2, n2;
//    cin >> m1 >> n1 >> m2 >> n2;
//    Matrix r1(m1, n1), r2(m2, n2);
//    cin >> r1 >> r2;
//    if ((m1 != m2) || (n1 != n2))
//    {
//        cout << "error" << endl << "error" << endl;
//    }
//    else if ((m1 == m2) && (n1 == n2))//�Ӽ�
//    {
//        r1 + r2;
//
//        r1 - r2;
//
//    }
//    if (n1 != m2)
//    {
//        cout << "error" << endl;
//    }
//    else if (n1 == m2)//��
//    {
//
//        r1* r2;
//
//    }
//    r1.transpose();//ת��
//
//    return 0;
//}

//#include<stdio.h>
//#include<graphics.h>
//#include<conio.h>
//#include<string.h>
////��ť����
//typedef struct Button
//{
//	int x;
//	int y;
//	int xx;
//	int yy;
//	COLORREF color;
//	char* buttonstr;
//}*LPBTN;
////������װ
//LPBTN createButton(int x, int y, int xx, int yy, COLORREF color, const char* buttonstr)
//{
//	LPBTN button = (LPBTN)malloc(sizeof(LPBTN));
//	button->x = x;
//	button->y = y;
//	button->xx = xx;
//	button->yy = yy;
//	button->color = color;
//	button->buttonstr = (char*)malloc(sizeof(char));
//	strcpy(button->buttonstr, buttonstr);
//
//	return button;
//}
////���ư�ť
//void drawButton(LPBTN button)
//{
//	setfillcolor(button->color);//���õ�ǰ�豸�����ɫ
//	fillrectangle(button->x, button->y, button->xx, button->yy);
//	setbkmode(TRANSPARENT); //����͸������
//	setlinecolor(BLACK);//���û�����ɫ
//	settextstyle(30, 0, "����"); //����ͼ���ı���ǰ���塢�ַ���С
//	outtextxy(button->x + 15, button->y + 10, button->buttonstr);//���ͼ���ı��ַ���
//}
////����Ƿ��ڰ�ť��
//int isInButton(LPBTN button, MOUSEMSG m)
//{
//	if (button->x <= m.x && button->xx >= m.x && button->y <= m.y && button->yy >= m.y)
//	{
//		return 1;
//	}
//	return 0;
//}
///*---------�������ǰ�������ɫ------------*/
//void buttonAction(LPBTN button, MOUSEMSG m)
//{
//	if (isInButton(button, m))
//	{
//		button->color = RED;
//	}
//	else
//	{
//		button->color = BLUE;
//	}
//}
//int main()
//{
//	//���û��ư�ť����
//	LPBTN play = createButton(300, 200, 450, 250, BLUE, "��ʼ��Ϸ");
//	LPBTN pause = createButton(300, 260, 450, 310, BLUE, "��ͣ��Ϸ");
//	LPBTN resume = createButton(300, 320, 450, 370, BLUE, "������Ϸ");
//	LPBTN close = createButton(300, 380, 450, 430, BLUE, "�˳���Ϸ");
//	initgraph(800, 500);
//	IMAGE picture;
//	loadimage(&picture, "background.jpg", 800, 500);
//	putimage(0, 0, &picture);
//
//	MOUSEMSG m;
//	while (1)
//	{
//		BeginBatchDraw();//������ͼ��������Ļ��˸
//
//		/*-----------���ư�ť��ʽ----------*/
//		drawButton(play);
//		drawButton(pause);
//		drawButton(resume);
//		drawButton(close);
//
//		m = GetMouseMsg();//��ȡ�����Ϣ
//		/*---------�������ǰ�������ɫ------------*/
//		buttonAction(play, m);
//		buttonAction(pause, m);
//		buttonAction(resume, m);
//		buttonAction(close, m);
//
//		EndBatchDraw();
//	}
//	_getch();
//	closegraph();
//	return 0;
//}

//#include<istream>
//#include<iostream>
//#include<stdlib.h>
//#include<graphics.h>
//#include<math.h>
//#include<conio.h>
//
//int main() {
//    // ��ʼ����ͼ����
//    initgraph(640, 480);  // ���ô��ڴ�СΪ640x480
//
//    // ���Ƶ�¼����UI
//    while (!_kbhit()) {  // ��û�а�������ʱѭ��
//        cleardevice();  // �����Ļ
//
//        // ���Ʊ���
//        setbkcolor(BLUE);
//        cleardevice();
//
//        // ���Ʊ���
//        settextcolor(YELLOW);
//        settextstyle(30, 0, _T("����"));
//        outtextxy(200, 100, _T("��Ϸ��¼"));
//
//        // �����û��������������
//        settextcolor(WHITE);
//        settextstyle(20, 0, _T("����"));
//        outtextxy(150, 200, _T("�û���:"));
//        rectangle(300, 190, 500, 220);
//        outtextxy(150, 250, _T("����:"));
//        rectangle(300, 240, 500, 270);
//
//        // ���Ƶ�¼��ť
//        setfillcolor(GREEN);
//        solidrectangle(250, 320, 390, 360);
//        settextcolor(WHITE);
//        settextstyle(20, 0, _T("����"));
//        outtextxy(290, 330, _T("��¼"));
//
//        // ˢ����Ļ��ʾ
//        FlushBatchDraw();
//
//        // ����ˢ���ʣ����������˸
//        Sleep(10);
//    }
//
//    // �رջ�ͼ����
//    closegraph();
//
//    return 0;
//}

//#include<stdio.h>
//#include <windows.h>
//#include<conio.h>
//#pragma comment(lib,"winmm.lib")
//#include<graphics.h>
//#include <iostream>
//#include <cstring>
//using namespace std;
//
////int main() {
////	mciSendString(TEXT("open ֻ����̫��~.mp3 alias BGM1"), NULL, 0, NULL);
////	mciSendString(TEXT("open �����~.mp3 alias BGM2"), NULL, 0, NULL);
////	mciSendString(TEXT("play BGM1 repeat"), NULL, 0, NULL);
////	mciSendString(TEXT("play BGM2 repeat"), NULL, 0, NULL);
////
////	system("pause");
////	return 0;
////}
//
//int main()
//{
//	IMAGE img[10];
//
//	initgraph(800, 450);
//
//	char path[50] = { 0 };
//
//
//	for (int i = 0; i < 10; i++)
//	{
//		sprintf(path, "picture/0%d.png", i + 1);
//
//		loadimage(&img[i], path, getwidth(), getheight());
//		putimage(0, 0, &img[i]);
//		Sleep(200);
//	}
//	
//	system("pause");
//	_getch();
//	closegraph();
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include<string>
//#include<iomanip>
//using namespace std;
//
//template <class T>
//class number
//{
//public:
//	int x;
//	T arr[100];
//	number(int x1)
//	{
//		x = x1;
//		for (int i = 0; i < x; i++)
//			arr[i] = 0;
//	}
//
//	void sum()
//	{
//		T s = 0;
//		for (int i = 0; i < x; i++)
//		{
//			s = s + arr[i];
//		}
//		cout << s << endl;
//	}
//
//	void sort()
//	{
//		T t;
//		for (int i = 0; i < x - 1; i++)
//		{
//			for (int j = 0; j < x - i - 1; j++)
//			{
//				if (arr[j + 1] < arr[j])
//				{
//					t = arr[j];
//					arr[j] = arr[j + 1];
//					arr[j + 1] = t;
//				}
//
//			}
//		}
//		cout << arr[0];
//		for (int i = 1; i < x; i++)
//			cout << " " << arr[i];
//	}
//
//	void average()
//	{
//		T s = 0;
//		for (int i = 0; i < x; i++)
//		{
//			s = s + arr[i];
//		}
//		float p, p1, p2;
//		p1 = s;
//		p2 = x;
//		p = p1 / p2;
//		cout << fixed << setprecision(2) << p << endl;
//	}
//};
//
//int main()
//{
//	int type, n;
//	cin >> type >> n;
//	if (type == 0)
//	{
//		number<int> n1(n);
//		for (int i = 0; i < n; i++)
//			cin >> n1.arr[i];
//		n1.sum();
//		n1.average();
//		n1.sort();
//	}
//	else if (type == 1)
//	{
//		number<float> n1(n);
//		n1.x = n;
//		for (int i = 0; i < n; i++)
//			cin >> n1.arr[i];
//		n1.sum();
//		n1.average();
//		n1.sort();
//	}
//	return 0;
//}

//#include <iostream>
//
//class Base {
//public:
//    Base() {
//        foo();  // �ڻ��๹�캯���е����麯��
//    }
//
//    virtual void foo() {
//        std::cout << "Base::foo()" << std::endl;
//    }
//};
//
//class Derived : public Base {
//public:
//    Derived() {
//        foo();  // �������๹�캯���е����麯��
//    }
//
//    void foo() override {
//        std::cout << "Derived::foo()" << std::endl;
//    }
//};
//
//int main() {
//    Derived d;
//    return 0;
//}

//#include <iostream>
//
//class Base {
//public:
//    virtual void foo() {
//        std::cout << "Base::foo()" << std::endl;
//    }
//};
//
//class Derived : public Base {
//public:
//    void foo() override {
//        std::cout << "Derived::foo()" << std::endl;
//    }
//};
//
//int main() {
//    Base* ptr = new Derived();
//    ptr->foo();  // ͨ��ָ����������麯��
//    delete ptr;
//    return 0;
//}

#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor" << std::endl;
    }

    ~Base() {
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived constructor" << std::endl;
    }

    ~Derived() {
        std::cout << "Derived destructor" << std::endl;
    }
};

int main() {
    Derived d;
    return 0;
}