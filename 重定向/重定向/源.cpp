void redirect(char *cmd)
{
	int fd = -1;//先定义文件描述符
	int redirect_count = 0;//计量到大于号的数量
	char *ptr = cmd;//通过ptr来指向cmd
	char *file = NULL;//定义重定向的文件名
	while (*ptr)//不为空进入循环
	{
		if (*ptr = '>')//重定向
		{
			*ptr++ = '\0';//找到大于号将其值0
			redirect_count++;//数量加1
			if (*ptr == '>')//追加重定向
			{
				*ptr++ = '\0';//找到第二个继续置0
				redirect_count++;//数量继续加加
			}
			while (*ptr != '\0' && isspace(*ptr))//如果空格就忽略让ptr++
			{
				*ptr++;
			}
			file = ptr;//到了第一个不为空格的值给file
			while (*ptr != '\0' && !isspace(*ptr))
			{
				*ptr++;
			}
			*ptr = '\0';//检测到空格停止
			if (1 == redirect_count)//判断数量来选择重定向

			{
				fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0664);//创建并清空
			}
			else if (2 == redirect_count)//判断数量来选择追加重定向
			{
				fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0664);//创建并追加
			}
			dup2(fd, 1);//通过dup2函数来将输出到显示器（1）上的数据给到文件
			close(fd);//关闭文件
		}
		ptr++;//不为空++
	}
}

