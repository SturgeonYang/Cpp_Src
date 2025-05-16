#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

// 三元组结构
struct Triple {
    int row;    // 行号
    int col;    // 列号
    int value;  // 值
};

// 稀疏矩阵类
class SparseMatrix {
private:
    int rows, cols;             // 矩阵的行数和列数
    vector<Triple> triples;     // 存储三元组

public:
    // 构造函数
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    // 添加三元组
    void addTriple(int row, int col, int value) {
        if (value != 0) {
            triples.push_back({row, col, value});
        }
    }

    // 打印矩阵
    void printMatrix() const {
        cout << "三元组表示：" << endl;
        for (const auto& triple : triples) {
            cout << "(" << triple.row << ", " << triple.col << ", " << triple.value << ")" << endl;
        }
    }

    // 转置矩阵
    SparseMatrix transpose() const {
        SparseMatrix result(cols, rows);
        for (const auto& triple : triples) {
            result.addTriple(triple.col, triple.row, triple.value);
        }
        return result;
    }

    // 矩阵相乘
    SparseMatrix multiply(const SparseMatrix& other) const {
        if (cols != other.rows) {
            throw invalid_argument("矩阵维度不匹配，无法相乘");
        }

        SparseMatrix result(rows, other.cols);
        map<pair<int, int>, int> tempResult;

        // 遍历矩阵 A 的三元组
        for (const auto& a : triples) {
            // 遍历矩阵 B 的三元组
            for (const auto& b : other.triples) {
                // 如果 A 的列号等于 B 的行号，进行乘积累加
                if (a.col == b.row) {
                    tempResult[{a.row, b.col}] += a.value * b.value;
                }
            }
        }

        // 将非零结果存储到结果矩阵中
        for (const auto& entry : tempResult) {
            if (entry.second != 0) {
                result.addTriple(entry.first.first, entry.first.second, entry.second);
            }
        }

        return result;
    }

    // 基于 Map-Reduce 的分布式矩阵相乘（模拟）
    SparseMatrix mapReduceMultiply(const SparseMatrix& other) const {
        return multiply(other); // 简化实现，实际分布式需要分片处理
    }
};

int main() {
    // 测试数据
    SparseMatrix A(4, 5);
    A.addTriple(0, 0, 4);
    A.addTriple(0, 1, -3);
    A.addTriple(0, 4, 1);
    A.addTriple(1, 3, 8);
    A.addTriple(2, 2, 1);
    A.addTriple(3, 4, 70);

    SparseMatrix B(5, 3);
    B.addTriple(0, 0, 3);
    B.addTriple(1, 0, 4);
    B.addTriple(1, 1, 2);
    B.addTriple(2, 1, 1);
    B.addTriple(3, 2, 1);

    // 打印矩阵 A 和 B
    cout << "矩阵 A：" << endl;
    A.printMatrix();
    cout << "矩阵 B：" << endl;
    B.printMatrix();

    // 转置矩阵 A
    cout << "\n矩阵 A 的转置：" << endl;
    SparseMatrix AT = A.transpose();
    AT.printMatrix();

    // 矩阵相乘 A * B
    cout << "\n矩阵 A * B：" << endl;
    try {
        SparseMatrix C = A.multiply(B);
        C.printMatrix();
    } catch (const exception& e) {
        cout << "错误：" << e.what() << endl;
    }

    // 基于 Map-Reduce 的矩阵相乘（模拟）
    cout << "\n基于 Map-Reduce 的矩阵相乘：" << endl;
    SparseMatrix D = A.mapReduceMultiply(B);
    D.printMatrix();

    return 0;
}