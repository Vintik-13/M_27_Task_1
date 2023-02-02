/*Задание 1. Реализация деревни эльфов

Что нужно сделать
Лесные эльфы расположили свою деревню в лесу, прямо на деревьях.
Нужно расселить эльфов по веткам деревьев, а затем подсчитать
общее количество соседей определённого эльфа.
Всего в лесу пять деревьев, каждое из которых генерируется с
помощью случайных чисел, заданных в указанных далее диапазонах.
На каждом дереве есть 3–5 основных больших ветвей. На каждой
большой ветке расположены ещё 2-3 средние ветки. Дома эльфов
построены на больших и на средних ветках. Более мелкие ветви
не рассматриваются в этой задаче.
В начале программы пользователь размещает в каждом доме по одному
эльфу. Делается это с помощью последовательного перебора всех
имеющихся домов и запроса имени заселяемого эльфа через стандартный
ввод. Если было введено None в качестве имени, то дом пропускается
и не заселяется никем.
После этого требуется найти определённого эльфа по имени. Имя
искомого эльфа вводится через стандартный ввод. Для найденного
эльфа нужно вывести общее количество эльфов, живущих вместе с ним
на одной большой ветви. Это и будет искомое количество соседей.*/

#include <iostream>
#include <string>
#include <vector>

std::string CreatNameBranch(std::string name, int prefix) {
    std::string tmp;
    tmp += name + "-" + std::to_string(prefix);
    
    return tmp;
}

class Branch {
    std::string nameBranch;

    std::string nameElf;

    Branch* parent;

    std::vector<Branch*> childs;    

public:
    Branch() : nameBranch{ "Tree" }, nameElf{ "No name" }, parent{nullptr} {}

    void CreatBranch(int level) {        

        if (level <= 0)
            return;

        Branch tmp;

        std::string name;

        if(this->parent == nullptr)
            std::cout << "No parent!\nThis name - " << this->nameBranch << "\nEnter the child's name: ";
        else
            std::cout << "Parent - " << this->parent->nameBranch << "\nThis name - " << this->nameBranch << "\nEnter the child's name: ";

        std::getline(std::cin, name);

        tmp.nameBranch = name;
        
        tmp.parent = this;

        this->childs.push_back(&tmp);

        level--;  

        this->ShowBranch();

        this->childs[this->childs.size() - 1]->CreatBranch(level);        
    }

    void CreatTree(int level) {

        Branch tmp;

        if (level != 0) {
            level--;
            CreatTree(level);
            
        }
        else
            return;
        if (this->parent == nullptr) {
            this->childs.push_back(&tmp);
            this->childs[this->childs.size() - 1]->nameBranch = ::CreatNameBranch(this->nameBranch, this->childs.size());
        }
        else {
            tmp.parent = this;
            this->childs.push_back(&tmp);
            this->nameBranch = ::CreatNameBranch(this->nameBranch, this->childs.size());
        }
        
        
        
    }

    void ShowBranch() {

        std::cout << std::endl;

        if (this->parent == nullptr) {
            std::cout << "Parent - " << "No name  " << "Parent = nullptr" << std::endl;
            std::cout << "This - " << this->nameBranch << "  " << this << std::endl;

        }
        else {
            std::cout << "Parent - " << parent->nameBranch << " " << this->parent << std::endl;
            std::cout << "This - " << this->nameBranch << "  " << this << std::endl;
        }

        std::cout << "Number of descendants: " << this->childs.size() << std::endl;

        for (int i = 0; i < this->childs.size(); i++) {
            std::cout << this->childs[i]->nameBranch;
        }
        std::cout << std::endl << std::endl;
    }

    void ShowTree() {
        this->ShowBranch();

        if (this->childs.size() == 0)
            return;
        
        for (auto p : this->childs)
            p->ShowTree();        
    }
};



int main()
{
    Branch ttt;

    ttt.ShowBranch();

    ttt.CreatBranch(3);

    ttt.ShowBranch();

    ttt.ShowTree();
   
}

