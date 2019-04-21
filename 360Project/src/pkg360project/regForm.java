/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg360project;

import java.sql.ResultSet;
import java.sql.Statement;
import javax.swing.JOptionPane;

/**
 *
 * @author tasos
 */
public class regForm extends javax.swing.JFrame {
DBConnect connect =new DBConnect();

    /**
     * Creates new form regForm
     */
    public regForm() {
        initComponents();
        connect.StudiesList();
        connect.Spec_list();
    }

    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        acclbl = new javax.swing.JLabel();
        streetlbl = new javax.swing.JLabel();
        pwdlbl = new javax.swing.JLabel();
        namelbl = new javax.swing.JLabel();
        phonelbl = new javax.swing.JLabel();
        maillbl = new javax.swing.JLabel();
        proflbl = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        stdlist = new javax.swing.JList<>();
        userlbl = new javax.swing.JLabel();
        creditlbl = new javax.swing.JLabel();
        spclbl = new javax.swing.JLabel();
        stdlbl = new javax.swing.JLabel();
        langlbl = new javax.swing.JLabel();
        jScrollPane3 = new javax.swing.JScrollPane();
        spclist = new javax.swing.JList<>();
        EngCk = new javax.swing.JCheckBox();
        GerCk = new javax.swing.JCheckBox();
        addtxt = new javax.swing.JTextField();
        usertxt = new javax.swing.JTextField();
        nametxt = new javax.swing.JTextField();
        pwdtxt = new javax.swing.JPasswordField();
        acctxt = new javax.swing.JTextField();
        credittxt = new javax.swing.JTextField();
        phonetxt = new javax.swing.JTextField();
        mailtxt = new javax.swing.JTextField();
        regbtn = new javax.swing.JButton();
        jScrollPane2 = new javax.swing.JScrollPane();
        prof_list = new javax.swing.JList<>();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("Register");
        setResizable(false);

        acclbl.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        acclbl.setText("Αρ.Λογαριασμού:");

        streetlbl.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        streetlbl.setText("Οδός:");

        pwdlbl.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        pwdlbl.setText("Κωδικός:");

        namelbl.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        namelbl.setText("Ονοματεπώνυμο");

        phonelbl.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        phonelbl.setText("Τηλέφωνο:");

        maillbl.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        maillbl.setText("E-mail:");

        proflbl.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        proflbl.setText("Επάγγελμα:");

        stdlist.setModel(new javax.swing.AbstractListModel<String>() {
            String[] strings=connect.StudiesList();
            public int getSize() { return strings.length; }
            public String getElementAt(int i) { return strings[i]; }
        });
        stdlist.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        stdlist.addListSelectionListener(new javax.swing.event.ListSelectionListener() {
            public void valueChanged(javax.swing.event.ListSelectionEvent evt) {
                stdlistValueChanged(evt);
            }
        });
        jScrollPane1.setViewportView(stdlist);

        userlbl.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        userlbl.setText("Ονομα χρήστη:");

        creditlbl.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        creditlbl.setText("Αρ.Πιστωτικής Κάρτας");

        spclbl.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        spclbl.setText("Δεξιότητες:");

        stdlbl.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        stdlbl.setText("Σπουδές");

        langlbl.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        langlbl.setText("Ξένες  Γλώσσες:");
        langlbl.setToolTipText("");

        spclist.setModel(new javax.swing.AbstractListModel<String>() {
            String[] strings = connect.Spec_list();
            public int getSize() { return strings.length; }
            public String getElementAt(int i) { return strings[i]; }
        });
        spclist.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        spclist.addListSelectionListener(new javax.swing.event.ListSelectionListener() {
            public void valueChanged(javax.swing.event.ListSelectionEvent evt) {
                spclistValueChanged(evt);
            }
        });
        jScrollPane3.setViewportView(spclist);

        EngCk.setText("English");
        EngCk.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                EngCkActionPerformed(evt);
            }
        });

        GerCk.setText("German");
        GerCk.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                GerCkActionPerformed(evt);
            }
        });

        mailtxt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                mailtxtActionPerformed(evt);
            }
        });

        regbtn.setText("register");
        regbtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                regbtnActionPerformed(evt);
            }
        });

        prof_list.setModel(new javax.swing.AbstractListModel<String>() {
            String[] strings = connect.Prof_list();
            public int getSize() { return strings.length; }
            public String getElementAt(int i) { return strings[i]; }
        });
        prof_list.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        prof_list.setToolTipText("");
        jScrollPane2.setViewportView(prof_list);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(20, 20, 20)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(12, 12, 12)
                                .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addGap(45, 45, 45)
                                .addComponent(spclbl)))
                        .addGap(79, 79, 79)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(stdlbl)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(regbtn))
                                    .addGroup(layout.createSequentialGroup()
                                        .addGap(304, 304, 304)
                                        .addComponent(proflbl)
                                        .addGap(0, 0, Short.MAX_VALUE))))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 106, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(langlbl)
                                    .addGroup(layout.createSequentialGroup()
                                        .addGap(10, 10, 10)
                                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                            .addComponent(GerCk)
                                            .addComponent(EngCk))))
                                .addGap(105, 105, 105))))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(userlbl)
                            .addComponent(pwdlbl)
                            .addComponent(streetlbl)
                            .addComponent(namelbl))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(nametxt, javax.swing.GroupLayout.DEFAULT_SIZE, 137, Short.MAX_VALUE)
                            .addComponent(usertxt)
                            .addComponent(pwdtxt)
                            .addComponent(addtxt))
                        .addGap(239, 239, 239)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(creditlbl)
                            .addComponent(acclbl)
                            .addComponent(phonelbl)
                            .addComponent(maillbl))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(0, 0, Short.MAX_VALUE))
                            .addComponent(acctxt)
                            .addComponent(credittxt)
                            .addComponent(phonetxt, javax.swing.GroupLayout.DEFAULT_SIZE, 526, Short.MAX_VALUE)
                            .addComponent(mailtxt)))))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(30, 30, 30)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(userlbl, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(usertxt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(11, 11, 11))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(acclbl, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(acctxt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)))
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(pwdlbl)
                            .addComponent(pwdtxt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(namelbl)
                            .addComponent(nametxt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(creditlbl, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(credittxt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(phonelbl)
                            .addComponent(phonetxt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addGap(24, 24, 24)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(maillbl)
                    .addComponent(streetlbl)
                    .addComponent(addtxt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(mailtxt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 295, Short.MAX_VALUE)
                .addComponent(regbtn)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(langlbl)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(EngCk)
                        .addGap(3, 3, 3)
                        .addComponent(GerCk)
                        .addGap(99, 99, 99))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(spclbl)
                            .addComponent(stdlbl)
                            .addComponent(proflbl))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(89, 89, 89))))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents
boolean ticked=false;
int lang_cnt=0;
    private void EngCkActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_EngCkActionPerformed

           if(ticked==false){
           ticked=true;
           lang_cnt=lang_cnt+1;
           }else{
                  ticked=false;
                  lang_cnt--;
                 
           }
           
    }//GEN-LAST:event_EngCkActionPerformed

    private void mailtxtActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_mailtxtActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_mailtxtActionPerformed

    private void regbtnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_regbtnActionPerformed
        // TODO add your handling code here:
        if(connect.individual_Exists(usertxt.getText())||connect.companyExists(usertxt.getText())){
            JOptionPane.showMessageDialog(null,"User Already Exists");
        }else{
            
            if(usertxt.getText().equals("")){
                JOptionPane.showMessageDialog(null, "Username is required");
            
           }else if(pwdtxt.getText().equals("")){
                JOptionPane.showMessageDialog(null, "Password is required");
           }else if(mailtxt.getText().equals("")){
                JOptionPane.showMessageDialog(null, "Email is required");
           }else if(addtxt.getText().equals("")){
                JOptionPane.showMessageDialog(null, "Address is required");
           }else if(phonetxt.getText().equals("")){
                JOptionPane.showMessageDialog(null, "Phone number is required");
           }else if(nametxt.getText().equals("")){
                JOptionPane.showMessageDialog(null, "Name is required");
           }else if(prof_list.getSelectedValue().equals(null)){
                JOptionPane.showMessageDialog(null, "Profession is required");
           }else if(acctxt.getText().equals("")){
                JOptionPane.showMessageDialog(null, "Account number is required");
           }else if(credittxt.getText().equals("")){
                JOptionPane.showMessageDialog(null, "Credit info is required");
           }else if(stdlist.getSelectedValue().equals(null)){
                JOptionPane.showMessageDialog(null, "Studies selection is required");
           }else{
        
                connect.registerIndividual(usertxt.getText(), pwdtxt.getText(), nametxt.getText(), addtxt.getText(), phonetxt.getText(), mailtxt.getText(), prof_list.getSelectedValue(), acctxt.getText(), credittxt.getText(),lang_cnt,stdlist.getSelectedValue(),spclist.getSelectedValue());
                JOptionPane.showMessageDialog(null, "Register completed");
                this.setVisible(false);
                dispose();
                }
       
        }
                              
    }//GEN-LAST:event_regbtnActionPerformed
boolean gticked=false;
    private void GerCkActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_GerCkActionPerformed
        if(gticked==false){
           gticked=true;
           lang_cnt=lang_cnt+2;
           }else{
                  gticked=false;
                  lang_cnt=lang_cnt-2;
           }
    }//GEN-LAST:event_GerCkActionPerformed

    private void stdlistValueChanged(javax.swing.event.ListSelectionEvent evt) {//GEN-FIRST:event_stdlistValueChanged
        // TODO add your handling code here:
       
    }//GEN-LAST:event_stdlistValueChanged

    private void spclistValueChanged(javax.swing.event.ListSelectionEvent evt) {//GEN-FIRST:event_spclistValueChanged
        // TODO add your handling code here:

    }//GEN-LAST:event_spclistValueChanged

  
  

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JCheckBox EngCk;
    private javax.swing.JCheckBox GerCk;
    private javax.swing.JLabel acclbl;
    private javax.swing.JTextField acctxt;
    private javax.swing.JTextField addtxt;
    private javax.swing.JLabel creditlbl;
    private javax.swing.JTextField credittxt;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JLabel langlbl;
    private javax.swing.JLabel maillbl;
    private javax.swing.JTextField mailtxt;
    private javax.swing.JLabel namelbl;
    private javax.swing.JTextField nametxt;
    private javax.swing.JLabel phonelbl;
    private javax.swing.JTextField phonetxt;
    private javax.swing.JList<String> prof_list;
    private javax.swing.JLabel proflbl;
    private javax.swing.JLabel pwdlbl;
    private javax.swing.JPasswordField pwdtxt;
    private javax.swing.JButton regbtn;
    private javax.swing.JLabel spclbl;
    private javax.swing.JList<String> spclist;
    private javax.swing.JLabel stdlbl;
    private javax.swing.JList<String> stdlist;
    private javax.swing.JLabel streetlbl;
    private javax.swing.JLabel userlbl;
    private javax.swing.JTextField usertxt;
    // End of variables declaration//GEN-END:variables
}
