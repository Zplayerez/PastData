//题目描述
//给定一个非最简的Linux文件绝对路径，将其简化为标准的Linux文件绝对路径。
//
//在Linux文件路径中，一个英文句号.表示当前目录，两个连续的英文句号 ..表示返回到上一级目录。
//
//标准的Linux文件绝对路径具有以下特点
//
//第一个字符为斜杠 /
//
//两个目录名称直接有且仅有一个斜杠 /
//
//除根目录外，路径结尾不能为斜杠 /
//
//不会出现一个英文句号.或者两个连续的英文句号 ..
//
//Input Format
//输入由一行字符串组成，为非最简的Linux文件绝对路径。
//
//Output Format
//输出一行，为最简化的Linux文件绝对路径。
//
//Example
//Input
/// aaa / .. / .. / bbb / ccc / ..///./..
//
//Output
///
//
//说明
//路径从根目录开始从左往右进行解析
//
//aaa 表示进入根目录下 aaa 目录
//
//..表示返回上一级目录，即返回根目录
//
//..表示返回上一级目录，但当前目录为根目录，无上一级目录。故仍处于根目录。
//
//bbb 表示进入根目录下 bbb 目录
//
//ccc 表示进入 bbb 目录下 ccc 目录
//
//..表示返回上一级目录，即返回 bbb 目录
//
//后续若干个连续的斜杠 / 间没有目录名称，直接删除
//
//.表示当期文件夹，故仍处于 bbb 目录
//
//..表示返回上一级目录，即返回根目录
//
//根目录用斜杠 / 表示，故输出斜杠 /
//
//
//
//样例输入输出
//样例1
//输入 :
/// aaa / .. / .. / bbb / ccc / ..///./..
//输出 :
//	/
//	样例2
//	输入 :
/// home /
//输出 :
//	/ home

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

string simplifyPath(string path) {
    stack<string> components;
    stringstream ss(path);
    string component;

    // 使用 '/' 作为分隔符将路径拆分成组件
    while (getline(ss, component, '/')) {
        if (component == "..") {
            // 如果组件为 ".."，表示返回上一级目录，弹出栈顶目录
            if (!components.empty()) {
                components.pop();
            }
        }
        else if (component != "." && !component.empty()) {
            // 忽略 "." 和空组件，将有效目录名推入栈
            components.push(component);
        }
    }

    // 构建简化后的路径
    vector<string> simplifiedComponents;
    while (!components.empty()) {
        simplifiedComponents.push_back(components.top());
        components.pop();
    }

    // 从栈中取出的目录是从右往左的，需要逆序构建路径
    string simplifiedPath = "/";
    for (int i = simplifiedComponents.size() - 1; i >= 0; --i) {
        simplifiedPath += simplifiedComponents[i];
        if (i > 0) {
            simplifiedPath += "/";
        }
    }

    return simplifiedPath;
}

int main() {
    string input;
    cin >> input;

    string simplified = simplifyPath(input);
    cout << simplified << endl;

    return 0;
}
