package model;

public class Course {
    private int id;
    private String name;
    private String content = "";
    private String member = "";
    private int price = 0;
    private String notice = "";
    private String remark = "";

    public Course(int id, String name, String content, String member, int price, String notice, String remark){
        this.id = id;
        this.name = name;
        this.content = content;
        this.member = member;
        this.price = price;
        this.notice = notice;
        this.remark = remark;
    }

    public int getId() { return id; }

    public String getName() { return name; }

    public String getContent() { return content; }

    public String getMember() { return member; }

    public int getPrice() { return price; }

    public String getNotice() { return notice; }

    public String getRemark() { return remark; }
}
