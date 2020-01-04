TARGET=main  #TARGET是一个变量
CC=gcc       #CC是一个变量
CFLAGS=-I ./inc #指定头文件和库文件路径: -L /lib/ 
DIRS= .    #  .c文件的路径
FILES=$(foreach dir,$(DIRS),$(wildcard $(dir)/*.c)) #foreach查找所有.c函数
OBJ=$(patsubst %.c,%.o,$(FILES))   #patsubst将所有的.c替换为.o文件

$(TARGET):$(OBJ)         
	$(CC)  $(OBJ) -o $(TARGET) $(CFLAGS)
	
clean:  #添加清除操作
	rm *.o $(TARGET)  #清除.o文件及执行文件