/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg360project;

import java.sql.*;
import java.util.ArrayList;
import java.util.Random;
import java.util.Vector;
import javax.swing.JOptionPane;

/**
 *
 * @author tasos
 */
public class DBConnect {
    public Connection con;
    public Statement st;
    public ResultSet rs;
    public boolean isIndividual=false;
    public String[] users;
    public DBConnect(){
        try{
            Class.forName("com.mysql.jdbc.Driver");
            con=DriverManager.getConnection("jdbc:mysql://localhost/headhunters","root","");
            st=null;
            
            
        }catch(Exception e){
            System.out.println("error"+e);
        }
    }
    
    //checks if username is already registered in idividuals sql table
    public boolean individual_Exists(String username){           
        try{
            PreparedStatement s=con.prepareStatement("select * from individuals where username = ?");
            s.setString(1, username);
            ResultSet r1=s.executeQuery();
            if(r1.next()){
                
                return true;
            }
            return false;
        }catch(Exception e){
            System.out.println("error"+e);
            return false;
        }
        
  
        
    }
    
    //checks if username is already registered in company sql table
    public boolean companyExists(String username){
        try{
            PreparedStatement s=con.prepareStatement("select * from company where username = ?");
            s.setString(1, username);
            ResultSet r1=s.executeQuery();
            if(r1.next()){
                return true;
            }
            
            return false;
        
        }catch(Exception e){
            System.out.println("error"+e);
            return false;
        }
        
        
    }
    
    public boolean jobId_Exists(int id){
        try{
          PreparedStatement s=con.prepareStatement("select * from job where id = ?");
          s.setInt(1, id);
          ResultSet r1=s.executeQuery();
          if(r1.next()){
              return true;
          }
            return false;
        }catch(Exception e){
            System.out.println("error"+e);
            return false;
        }
    }
    public void registerIndividual (String username,String pwd,String name,String address,String phone,String email,String prof,String acc,String credits, int lang,String studies,String spec){ //registers an individual
        boolean userexists=false;   //true if user already exists
        try{
         
                Random rand =new Random();
                int Amount =rand.nextInt(10000);
                String bank_query="insert into bank_accounts (ACC,CREDIT,Amount)"+"values(?,?,?)";
                String query ="insert into individuals (username,password,name,address,phone,email,profession,acc,credit,language,studies,specialty)"+"values (?,?,?,?,?,?,?,?,?,?,?,?)";
                PreparedStatement bank_state=con.prepareStatement(bank_query);
                PreparedStatement smt=con.prepareStatement(query);
                smt.setString(1, username);
                smt.setString(2,pwd);
                smt.setString(3, name);
                smt.setString(4, address);
                smt.setString(5, phone);
                smt.setString(6, email);
                smt.setString(7, prof);
                smt.setString(8, acc);
                smt.setString(9, credits);
                smt.setInt(10, lang);
                smt.setString(11, studies);
                smt.setString(12, spec);
                smt.execute();
                bank_state.setString(1, acc);
                bank_state.setString(2, credits);
                bank_state.setDouble(3, Amount);
                bank_state.execute();
   
        }catch(Exception e){
            System.out.println("error"+e);
           
        }
    }
    public void registerCompany(String username,String password,String name,String phone,String email,String acc,String credit,String add){//registers a company
         
        try{
              Random rand =new Random();
              int Amount=rand.nextInt(10000);
              String bank_query="insert into bank_accounts (ACC,CREDIT,Amount)"+"values(?,?,?)";
              String query="insert into company (username,password,phone,email,name,account,credit,address,posts)"+"values(?,?,?,?,?,?,?,?,?)";
              PreparedStatement bank_state=con.prepareStatement(bank_query);
              PreparedStatement stm=con.prepareStatement(query);
              stm.setString(1,username);
              stm.setString(2, password);
              stm.setString(3, phone);
              stm.setString(4, email);
              stm.setString(5,name);
              stm.setString(6,acc);
              stm.setString(7, credit);
              stm.setString(8, add);
              stm.setInt(9, 0);
              stm.execute();        
              bank_state.setString(1, acc);
              bank_state.setString(2, credit);
              bank_state.setDouble(3, Amount);
              bank_state.execute();
               
        }catch(Exception e){
            System.out.println("Error"+e);
        }
    }
    
    public void PostJob(int id,String profession,String description,String specialties,String studies,int lang,String town,String time,int pays,String username){
        try{
            PreparedStatement st=con.prepareStatement("insert into job (id,profession,description,specialties,studies,language,town,time,pays,username)"+"values(?,?,?,?,?,?,?,?,?,?)");
            
            st.setInt(1, id);
            st.setString(2, profession);
            st.setString(3, description);
            st.setString(4, specialties);
            st.setString(5, studies);
            st.setInt(6, lang);
            st.setString(7, town);
            st.setString(8, time);
            st.setInt(9, pays);
            st.setString(10, username);
            st.execute();
        }catch(Exception e){
            System.out.println("error"+e);
        }
        
        
    }
    
    public boolean admin_login(String username,String password){
        try{
            String sql="select *from admin where username=? and password=?";
            PreparedStatement st=con.prepareStatement(sql);
            st.setString(1, username);
            st.setString(2, password);
            rs=st.executeQuery();
            if(rs.next()){
                JOptionPane.showMessageDialog(null, "Login succesful");
                return true;
            }else{
                JOptionPane.showMessageDialog(null, "Wrong Password or Username!");
                return false;
            }
            
        }catch(Exception e){
            System.out.println("error"+e);
            return false;
        }
        
    }
    public boolean login(String username,String password){
        
        try{
        String sql_ind="select * from individuals where username=? and password=?";
        String sql_comp="select * from company where username=? and password=?";
        PreparedStatement stm_in=con.prepareStatement(sql_ind);
        PreparedStatement stm_comp=con.prepareStatement(sql_comp);
        
        stm_in.setString(1, username);
        stm_in.setString(2, password);
        stm_comp.setString(1,username);
        stm_comp.setString(2, password);
        
        rs=stm_in.executeQuery();//result from individual query//
        ResultSet result=stm_comp.executeQuery(); //result from company query
        
        if(rs.next()){ //checks if individuals result set is non empty
            JOptionPane.showMessageDialog(null, "Login Sucessful");
            this.isIndividual=true;
            return true;
        }else if(result.next()){//else checks if company result is non empty
            JOptionPane.showMessageDialog(null, "Login Sucessful");
            this.isIndividual=false;
            return true;
        }   else{              //login wasnt sucessful. both results are empty
            JOptionPane.showMessageDialog(null, "Username or password is incorrect");
            return false;
        }
       
        
        
        
        }catch(Exception e){
            System.out.println("error"+e);
        }
        
        return false;
    }
  
    
    //returns an individual by username
    public String[] getIndividual(String username){
        String[] individual=new String[10];
        try{
            
            String query="select distinct * from individuals where username=?";
            PreparedStatement state=con.prepareStatement(query);
            state.setString(1, username);
            rs=state.executeQuery();
            while(rs.next()){
              individual[0]=rs.getString("name");
              individual[1]=rs.getString("address");
              individual[2]=rs.getString("phone");
              individual[3]=rs.getString("email");
              individual[4]=rs.getString("profession");
              individual[5]=rs.getString("acc");
              individual[6]=rs.getString("credit");
              individual[7]=rs.getString("language");
              individual[8]=rs.getString("studies");
              individual[9]=rs.getString("specialty");
    
            }
            return individual;
            
            
        }catch(Exception e){
            System.out.println("error"+e);
        }
            return null;
    }
    
    public String[] getCompany(String username){
        String [] company=new String[6];
        try{
            String query="select * from company where username=?";
            PreparedStatement state=con.prepareStatement(query);
            state.setString(1, username);
            rs=state.executeQuery();
            while(rs.next()){
                company[0]=rs.getString("name");
                company[1]=rs.getString("phone");
                company[2]=rs.getString("email");
                company[3]=rs.getString("account");
                company[4]=rs.getString("credit");
                company[5]=rs.getString("address");
                
            }
            return company;
        }catch(Exception e){
            System.out.println("error"+e);   
    }
    return null;
    }
    public String[] getJob(int id){
        String[] job=new String[7];
        try{
            String query="select * from job where id=?";
            PreparedStatement state=con.prepareStatement(query);
            state.setInt(1, id);
            rs=state.executeQuery();
            while(rs.next()){
                job[0]=rs.getString("profession");
                job[1]=rs.getString("description");
                job[2]=rs.getString("specialties");
                job[3]=rs.getString("studies");
                job[4]=rs.getString("language");
                job[5]=rs.getString("town");
                job[6]=rs.getString("pays");
                
            }
            return job;
        }catch(Exception e){
            System.out.println("erro"+e);
        return job;
        }
    }
    //returns an array of strings containing the studies table
   public String[] StudiesList(){
String[] studies=new String[5];
int i=0;

       try{
           String query="select * from studies";
           PreparedStatement sts=con.prepareStatement(query);
           rs=sts.executeQuery(query);
           while(rs.next()){
               studies[i]=rs.getString("title");
             
          i++;
          
           }
           return studies;
           
       }catch(Exception e){
           System.out.println("Error"+e);
           
       }
       return null;
   }
   
   //returns an array of strings containing the profession table
   public String[] Spec_list(){
       String [] specs=new String[16];
       int i=0;
       try{
           String query="select * from specialties";
           PreparedStatement sts=con.prepareStatement(query);
           rs=sts.executeQuery();
           while(rs.next()){
               specs[i]=rs.getString("spec_name");
               i++;
           }
           return specs;
       }catch (Exception e){
           System.out.println("error"+e);
           return null;
       }
   }
   
   public String[] Prof_list(){
       String[] prof=new String[6];
       int i=0;
       try{
           String query="select * from profession";
           PreparedStatement sts=con.prepareStatement(query);
           rs=sts.executeQuery();
           while(rs.next()){
               prof[i]=rs.getString("title");
               i++;
           }
           return prof;
       }catch(Exception e){
           System.out.println("error"+e);
           return null;
       }
       
   }
   
   public int get_comp_posts(String username){
       String query="select posts from company where username = ?";
       try{
       PreparedStatement sts=con.prepareStatement(query);
       sts.setString(1, username);
       rs=sts.executeQuery();
       while(rs.next()){
          int x=rs.getInt("posts");
          return x;
       }
       }catch(Exception e){
           System.out.println("error"+e);
           return 0;
       }
       return 0;
   }
   
   public void update_comp_post(String username){
       int posts=this.get_comp_posts(username);
       posts++;
       String query="update company set posts=? where username=?";
       try{
       PreparedStatement sts=con.prepareStatement(query);
       sts.setInt(1, posts);
       sts.setString(2, username);
       sts.executeUpdate();
      
       }catch(Exception e){
           System.out.println("error"+e);
       }
   }  
   
   public double get_amount(String ACC,String Credit){
       String query="select Amount from bank_accounts where ACC=? AND CREDIT=? ";
       double amount=0;
       try{
           PreparedStatement sts=con.prepareStatement(query);
           sts.setString(1, ACC);
           sts.setString(2, Credit);
           rs=sts.executeQuery();
           while(rs.next()){
               amount=rs.getInt("Amount");
               return amount;
           }
       }catch(Exception e){
           System.out.println("error"+e);
       return 0;
       }
       return 0;
   }
   
   public boolean company_pay(String username,String ACC,String Credit){
       int posts=this.get_comp_posts(username);
       double amount=this.get_amount(ACC, Credit);
       double head_amount=this.get_amount("head1","--");
       if(posts>=3 && posts<5){
           amount=amount -(2-0.1*2);
           head_amount=head_amount+(2-0.1*2);
       }else if(posts>=5){
           amount =amount-(2-0.2*2);
           head_amount=head_amount+(2-0.2*2);
       }else{
           amount=amount-2;
           head_amount=head_amount+2;
       }
       String query="update bank_accounts set Amount=? where ACC=? AND CREDIT=?";
       String head="update bank_accounts set Amount=? where ACC=?";
       try{
           if(amount>0){
           PreparedStatement sts=con.prepareStatement(query);
           PreparedStatement heads=con.prepareStatement(head);
          sts.setDouble(1, amount);
          sts.setString(2, ACC);
          sts.setString(3, Credit);
          heads.setDouble(1, head_amount);
          heads.setString(2, "head1");
          sts.executeUpdate();
          heads.executeUpdate();
          return true;
           }else{
               JOptionPane.showMessageDialog(null, "Το υπόλοιπό σας δεν επαρκεί");
               return false;
           }
       }catch(Exception e){
           System.out.println("error"+e);
           return false;
       }
       
       
   }
   public boolean individual_pay(String username,String ACC,String Credit){
       double amount=this.get_amount(ACC, Credit);
       double head_amount=this.get_amount("GR5123987356","no_credit");
       System.out.println(head_amount);
       
       String query="update bank_accounts set Amount=? where ACC=? AND CREDIT=?";
       String head="update bank_accounts set Amount=? where ACC='GR5123987356' AND CREDIT='no_credit'";
       amount=amount-2;
       head_amount=head_amount+2;
       System.out.println(head_amount);
       try{
           if(amount>0){
               PreparedStatement sts=con.prepareStatement(query);
               PreparedStatement heads=con.prepareStatement(head);
               sts.setDouble(1, amount);
               sts.setString(2, ACC);
               sts.setString(3, Credit);
                heads.setDouble(1, head_amount);
         
          
          heads.executeUpdate();
               sts.executeUpdate();
               return true;
           }else{
               JOptionPane.showMessageDialog(null, "Το υπόλοιπό σας δεν επαρκεί");
               return false;
           }
           
       }catch(Exception e){
           System.out.println("error"+e);
           return false;
       }
   }
   
   public void proslipsh(String comp,String user){
       String query="update matching set status=? where comp_name=? and user=?";
       try{
           PreparedStatement sts=con.prepareStatement(query);
           sts.setInt(1, 1);
           sts.setString(2, comp);
           
           sts.setString(3, user);
           sts.executeUpdate();
           JOptionPane.showMessageDialog(null, "Η πρόσληψη ολοκληρώθηκε");
           
       }catch(Exception e){
           System.out.println("error"+e);
       }
       
   }
   public void post_application(String username,String profession,String specialty){
      String query="insert into applications (profession,specialty,username)"+"values(?,?,?)";
      try{
      PreparedStatement st=con.prepareStatement(query);
      st.setString(1, profession);
      st.setString(2, specialty);
      st.setString(3, username);
      st.execute();
      }catch(Exception e){
          System.out.println("error"+e);
      }
   }
   
   public void matching(){
String query="insert into matching (user,Id,comp_name) SELECT applications.username, job.id,job.username FROM applications INNER JOIN job ON job.profession=applications.profession AND job.specialties=applications.specialty";
       try{
           PreparedStatement st=con.prepareStatement(query);
           st.execute();
           JOptionPane.showMessageDialog(null, "Matching complete");
              
           
           
       }catch(Exception e){
           System.out.println("error"+e);
       }
   }
   public int countJobs(){
       try{
           
       Statement st=con.createStatement();
       ResultSet rs3=st.executeQuery("SELECT COUNT(*) AS total FROM job ");
       while(rs3.next()){
           return rs3.getInt("total");
       }
       }catch(Exception e){
           System.out.println("error "+e);
       }
       return 0;
   }
   public int countStated(){
       try{
           Statement st=con.createStatement();
           ResultSet rs=st.executeQuery("SELECT COUNT(DISTINCT Id) AS total FROM matching WHERE status=1");
           while(rs.next()){
               return rs.getInt("total");
           }
       }catch(Exception e){
           System.out.println("error"+e);
       }
       return 0;
   }
  
  
   
  
}
