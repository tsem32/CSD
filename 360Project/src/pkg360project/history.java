/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg360project;

import java.sql.PreparedStatement;
import javax.swing.JOptionPane;

/**
 *
 * @author tasos
 */
public class history extends javax.swing.JFrame {
DBConnect connect=new DBConnect();

    /**
     * Creates new form history
     */
    public history() {
        initComponents();
        
        if(this.Fillcombo()){
            System.out.println("true");
            this.setVisible(true);
        }else{
            this.dispose();
            System.out.println("false");
        }
              
        
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        combo = new javax.swing.JComboBox<>();
        prof_lbl = new javax.swing.JLabel();
        spec_lbl = new javax.swing.JLabel();
        std_lbl = new javax.swing.JLabel();
        town_lbl = new javax.swing.JLabel();
        lang_lbl = new javax.swing.JLabel();
        pays_lbl = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        area = new javax.swing.JTextArea();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        cnt_lbl = new javax.swing.JLabel();
        stated_lbl = new javax.swing.JLabel();
        jButton1 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        area.setEditable(false);
        area.setColumns(20);
        area.setRows(5);
        jScrollPane1.setViewportView(area);

        jLabel7.setText("Σύνολο θέσεων εργασίας:");

        jLabel8.setText("Στελεχωμένες:");

        jButton1.setText("Προβολή");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(combo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jButton1)))
                .addGap(64, 64, 64)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 268, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(std_lbl))
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(prof_lbl)
                            .addComponent(spec_lbl))
                        .addGap(180, 180, 180)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(town_lbl)
                            .addComponent(pays_lbl)
                            .addComponent(lang_lbl, javax.swing.GroupLayout.PREFERRED_SIZE, 147, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addContainerGap(153, Short.MAX_VALUE))))
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel7, javax.swing.GroupLayout.PREFERRED_SIZE, 134, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(cnt_lbl))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel8, javax.swing.GroupLayout.PREFERRED_SIZE, 126, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(stated_lbl)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(combo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jButton1)
                .addGap(38, 38, 38)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel7)
                    .addComponent(cnt_lbl))
                .addGap(35, 35, 35)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel8)
                    .addComponent(stated_lbl))
                .addGap(22, 22, 22))
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(prof_lbl)
                    .addComponent(town_lbl))
                .addGap(34, 34, 34)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(spec_lbl)
                    .addComponent(pays_lbl))
                .addGap(35, 35, 35)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(std_lbl)
                    .addComponent(lang_lbl))
                .addGap(69, 69, 69)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 92, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(143, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        // TODO add your handling code here:
        String[] job=connect.getJob(Integer.parseInt(combo.getSelectedItem().toString()));
        prof_lbl.setText(job[0]);
        area.setText(job[1]);
        spec_lbl.setText(job[2]);
        std_lbl.setText(job[3]);
        cnt_lbl.setText(Integer.toString(connect.countJobs()));
        stated_lbl.setText(Integer.toString(connect.countStated()));
        if(job[4].equals("0")){
            lang_lbl.setText("καμία");
        }else if(job[4].equals("1")){
            lang_lbl.setText("Αγγλικά");
        }else if(job[4].equals("2")){
            lang_lbl.setText("Γερμανικά");
        }else{
            lang_lbl.setText("Αγγλικά,Γερμανικά");
        }
        town_lbl.setText(job[5]);
        pays_lbl.setText(job[6]);
    }//GEN-LAST:event_jButton1ActionPerformed

  public boolean Fillcombo(){
     try{
        String sql="select id from job";
        PreparedStatement pst=connect.con.prepareStatement(sql);
        connect.rs=pst.executeQuery();
        
        while(connect.rs.next()){
            int name=connect.rs.getInt("id");
            System.out.println(name);
            combo.addItem(Integer.toString(name));
           
        }
        return true;
       
            
           
        
    }catch(Exception e){
        System.out.println("error"+e);
        JOptionPane.showMessageDialog(null,"Το ιστορικό δεν είναι διαθέσιμο αυτή τη στιγμή");
    return false;
    }
}


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextArea area;
    private javax.swing.JLabel cnt_lbl;
    private javax.swing.JComboBox<String> combo;
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JLabel lang_lbl;
    private javax.swing.JLabel pays_lbl;
    private javax.swing.JLabel prof_lbl;
    private javax.swing.JLabel spec_lbl;
    private javax.swing.JLabel stated_lbl;
    private javax.swing.JLabel std_lbl;
    private javax.swing.JLabel town_lbl;
    // End of variables declaration//GEN-END:variables
}
