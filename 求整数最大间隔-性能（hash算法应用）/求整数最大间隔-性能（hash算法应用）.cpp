//题目描述
//请输出数字序列的最大间隔。
//请使用以下伪随机数生成函数 rand32() 生成伪随机数
//int seed;
//int rand() { return(((seed = seed * 214013L + 2531011L) >> 16) & 0x7fff); }
//int rand32() {
//	return ((rand() << 16) + (rand() << 1) + rand() % 2);
//}
//Input Format
//2个整数，n seed 其中 2 < n <= 20000000，seed为随机数种子。
//	Output Format
//	整数序列的最大间隔
//	Example
//	Input
//	2000000
//	1
//	Output
//	15737
//
//	样例
//	输入 :
//1959000 4910
//输出 :
//	16709

