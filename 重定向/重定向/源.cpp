void redirect(char *cmd)
{
	int fd = -1;//�ȶ����ļ�������
	int redirect_count = 0;//���������ںŵ�����
	char *ptr = cmd;//ͨ��ptr��ָ��cmd
	char *file = NULL;//�����ض�����ļ���
	while (*ptr)//��Ϊ�ս���ѭ��
	{
		if (*ptr = '>')//�ض���
		{
			*ptr++ = '\0';//�ҵ����ںŽ���ֵ0
			redirect_count++;//������1
			if (*ptr == '>')//׷���ض���
			{
				*ptr++ = '\0';//�ҵ��ڶ���������0
				redirect_count++;//���������Ӽ�
			}
			while (*ptr != '\0' && isspace(*ptr))//����ո�ͺ�����ptr++
			{
				*ptr++;
			}
			file = ptr;//���˵�һ����Ϊ�ո��ֵ��file
			while (*ptr != '\0' && !isspace(*ptr))
			{
				*ptr++;
			}
			*ptr = '\0';//��⵽�ո�ֹͣ
			if (1 == redirect_count)//�ж�������ѡ���ض���

			{
				fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0664);//���������
			}
			else if (2 == redirect_count)//�ж�������ѡ��׷���ض���
			{
				fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0664);//������׷��
			}
			dup2(fd, 1);//ͨ��dup2���������������ʾ����1���ϵ����ݸ����ļ�
			close(fd);//�ر��ļ�
		}
		ptr++;//��Ϊ��++
	}
}

