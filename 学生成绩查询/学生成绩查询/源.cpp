public class Test
{
	public static void main(String[] args)
	{
		List<student>list = new ArrayList<>();
		while (1)
		{
			String sc = new Scanner(System.in);
		}
	}
	private static void addStudent(List<Student> list)
	{
		Scanner sc1 = new Scanner(System.in);
		System.out.println("����������");
		int id = sc1.nextInt();
		sc1.nextLine();
		System.out.println("���������ĳɼ�");
		String ch = sc1.nextLine();
		System.out.println("��������ѧ�ɼ�");
		String math = sc1.nextLine();
		System.out.println("������Ӣ��ɼ�");
		Integer english = sc1.nextInt();
		Student student = new Student();
		student.setsId(id);
		student.setsName(ch);
		student.setsSex(math);
		student.setsAge(english);
		list.add(student);
		System.out.println("��ӳɹ���");
	}
	private static void selStudent(List<Student> list)
	{
		int sumchinese = 0;
		int summath = 0;
		int avg = 0;
		int maxenglish = 0;
		for (int i = 0; i<list.size(); i++)
		{
			Student s = list.get(i);
			System.out.println("����" + s.getsId() + "\t" + "����" + s.getsch() + "\t" + "��ѧ" + s.getsmath() + "\t" + "Ӣ��" + s.getsenglish());
			sumchinese = sumchinese + s.getsch();//�����ܷ�
			summath = summath + s.getsmath();//��ѧ�ܷ�
			avg = summath / list.size();//��ѧƽ����
			maxenglish = s.getsenglish>maxenglish ? s.getsenglish : maxenglish;//Ӣ����߷�
		}
		for (int i = 0; i < list.size(); i++)
		{
			Student s = list.get(i);
			if (s.getsenglish == maxenglish)
			{
				System.out.println("��߷�����" + s.getsId() + "\t");
			}
		}
	}
};