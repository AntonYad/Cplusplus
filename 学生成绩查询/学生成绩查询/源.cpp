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
		System.out.println("请输入姓名");
		int id = sc1.nextInt();
		sc1.nextLine();
		System.out.println("请输入语文成绩");
		String ch = sc1.nextLine();
		System.out.println("请输入数学成绩");
		String math = sc1.nextLine();
		System.out.println("请输入英语成绩");
		Integer english = sc1.nextInt();
		Student student = new Student();
		student.setsId(id);
		student.setsName(ch);
		student.setsSex(math);
		student.setsAge(english);
		list.add(student);
		System.out.println("添加成功！");
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
			System.out.println("姓名" + s.getsId() + "\t" + "语文" + s.getsch() + "\t" + "数学" + s.getsmath() + "\t" + "英语" + s.getsenglish());
			sumchinese = sumchinese + s.getsch();//语文总分
			summath = summath + s.getsmath();//数学总分
			avg = summath / list.size();//数学平均分
			maxenglish = s.getsenglish>maxenglish ? s.getsenglish : maxenglish;//英语最高分
		}
		for (int i = 0; i < list.size(); i++)
		{
			Student s = list.get(i);
			if (s.getsenglish == maxenglish)
			{
				System.out.println("最高分姓名" + s.getsId() + "\t");
			}
		}
	}
};