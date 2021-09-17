#include <cstdio>
#include <map>
#include "linkedlist.h"
#include <windows.h>
using namespace std;
const char LANG_NUMBER[] = "序号";
const char LANG_NAME[] = "物品名称";
const char LANG_QTY[] = "数量";
const char LANG_PLS_INPUT[] = "请输入";
const char LANG_WARES_EMPTY[] = "当前仓库为空！";
const char LANG_WELCOME[] = "欢迎来到电子科技大学仓库系统！";
const char LANG_1[] = "显示存货列表";
const char LANG_2[] = "入库";
const char LANG_3[] = "出库";
const char LANG_4[] = "保存并退出";
const char LANG_ATTR_CNT[] = "属性数量";
const char LANG_ATTR[] = "属性";
const char LANG_ATTR_NAME[] = "属性名称";
const char LANG_ATTR_CONTENT[] = "属性内容";

struct mystring{
    linkedlist<char> data;
    bool operator<(const mystring &b) const{
        if(data.size() != b.data.size()) return data.size() < b.data.size();
        for(linkedlist<char>::iterator i = data.begin(), j = b.data.begin(); i != data.end(); i++, j++){
            if(*i != *j) return *i < *j;
        }
        return false;
    }
};

void mygetline(FILE *in, linkedlist<char> &str){
    str.clear();
    char c = getc(in);
    while(c != '\n') {
        str.push_back(c);
        c = getc(in);
    }
}
void myprint(FILE *out, const linkedlist<char> &str){
    for(char c : str)
        putc(c, out);
}

struct ware{
    int qty;
    struct attribute{
        linkedlist<char> attr_name, attr_content;
    };
    linkedlist<attribute> attr;
};

map<mystring, ware> wares;
void printwares(){
    if(wares.empty()){
        puts(LANG_WARES_EMPTY);
        return;
    }
    int cnt = 0;
    for(auto pr : wares) {
        printf("%s: %d\n", LANG_NUMBER, ++cnt);
        printf("%s: ", LANG_NAME);
        myprint(stdout, pr.first.data);
        putchar('\n');
        printf("%s: %d\n", LANG_QTY, pr.second.qty);
        for (auto &attr: pr.second.attr) {
            myprint(stdout, attr.attr_name);
            printf(": ");
            myprint(stdout, attr.attr_content);
            putchar('\n');
        }
        putchar('\n');
    }
}

mystring ware_name;
int ware_cnt, attr_cnt;
ware ware_tmp;
ware::attribute attr_tmp;

int main(){
    FILE *in = fopen("storage.txt", "r");
    if(in){
        fscanf(in, "%d", &ware_cnt);
        getc(in);
        for(int i = 0; i < ware_cnt; i++){
            ware_tmp = ware();
            mygetline(in, ware_name.data);
            fscanf(in, "%d%d", &ware_tmp.qty, &attr_cnt);
            getc(in);
            for(int j = 0; j < attr_cnt; j++){
                mygetline(in, attr_tmp.attr_name);
                mygetline(in, attr_tmp.attr_content);
                ware_tmp.attr.push_back(attr_tmp);
            }
            wares[ware_name] = ware_tmp;
        }
    }
    bool noClose = true;
    while(noClose){
        system("cls");
        printf("%s\n1.%s\n2.%s\n3.%s\n4.%s\n%s%s: ", LANG_WELCOME, LANG_1, LANG_2, LANG_3, LANG_4, LANG_PLS_INPUT, LANG_NUMBER);
        int opt;
        scanf("%d", &opt);
        getchar();
        system("cls");
        switch(opt){
            case 1:
                printwares();
                break;
            case 2:
                ware_tmp = ware();
                printf("%s%s: ", LANG_PLS_INPUT, LANG_NAME);
                mygetline(stdin, ware_name.data);
                printf("%s%s: ", LANG_PLS_INPUT, LANG_QTY);
                scanf("%d", &ware_tmp.qty);
                getchar();
                if(wares.find(ware_name) != wares.end()){
                    wares[ware_name].qty += ware_tmp.qty;
                    break;
                }
                printf("%s%s: ", LANG_PLS_INPUT, LANG_ATTR_CNT);
                scanf("%d", &attr_cnt);
                getchar();
                for(int i = 1; i <= attr_cnt; i++){
                    printf("请输入 %s%d %s: ", LANG_ATTR, i, LANG_ATTR_NAME);
                    mygetline(stdin, attr_tmp.attr_name);
                    printf("请输入 %s%d %s: ", LANG_ATTR, i, LANG_ATTR_CONTENT);
                    mygetline(stdin, attr_tmp.attr_content);
                    ware_tmp.attr.push_back(attr_tmp);
                }
                wares[ware_name] = ware_tmp;
                break;
            case 3:
                printf("%s%s: ", LANG_PLS_INPUT, LANG_NAME);
                mygetline(stdin, ware_name.data);
                printf("%s%s: ", LANG_PLS_INPUT, LANG_QTY);
                scanf("%d", &ware_tmp.qty);
                getchar();
                wares[ware_name].qty -= ware_tmp.qty;
                if(!wares[ware_name].qty) wares.erase(ware_name);
                break;
            case 4:
                noClose = false;
                break;
            default:
                break;
        }
        printf("按下回车键继续...");
        getchar();
    }
    if(in) fclose(in);
    FILE *out = fopen("storage.txt", "w");
    fprintf(out, "%d\n", wares.size());
    for(auto &pr : wares){
        myprint(out, pr.first.data), putc('\n', out);
        fprintf(out, "%d\n%d\n", pr.second.qty, pr.second.attr.size());
        for(auto &attr : pr.second.attr){
            myprint(out, attr.attr_name), putc('\n', out);
            myprint(out, attr.attr_content), putc('\n', out);
        }
    }
    return 0;
}
