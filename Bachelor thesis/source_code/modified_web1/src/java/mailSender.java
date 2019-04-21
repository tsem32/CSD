/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.Properties;
import javax.mail.Message;
import javax.mail.MessagingException;
import javax.mail.PasswordAuthentication;
import javax.mail.Session;
import javax.mail.Transport;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;
/**
 *
 * @author laptop
 */
public class mailSender {
    void send(String toEmail,String Username,String Password){
                final String username = "logariasmoi.nos@gmail.com";
		final String password = "admin123!";

		Properties props = new Properties();
		props.put("mail.smtp.auth", "true");
		props.put("mail.smtp.starttls.enable", "true");
		props.put("mail.smtp.host", "smtp.gmail.com");
		props.put("mail.smtp.port", "587");

		Session session = Session.getInstance(props,
		  new javax.mail.Authenticator() {
			protected PasswordAuthentication getPasswordAuthentication() {
				return new PasswordAuthentication(username, password);
			}
		  });

		try {

			Message message = new MimeMessage(session);
			message.setFrom(new InternetAddress("logariasmoi.nos@gmail.com"));
			message.setRecipients(Message.RecipientType.TO,
				InternetAddress.parse(toEmail));
			message.setSubject("Λογαριασμός Χρήστη");
			message.setText("username: "+ Username
				+ "\n\n password: "+Password+"\n\n πραγματοποιήστε είσοδο με αυτά τα παραπάνω στοιχεία \n Για λόγους ασφαλείας"
                                + " \n σας παρακαλούμε  να τα αλλάξετε απο τις ρυθμίσεις προφίλ."
                                
                                + "\n\n ΜΗΝ ΑΠΑΝΤΗΣΕΤΕ ΣΕ ΑΥΤΟ ΤΟ ΜΥΝΗΜΑ"
                                 );

			Transport.send(message);

			System.out.println("Done");

		} catch (MessagingException e) {
			throw new RuntimeException(e);
		}
    }
    
     void send_AlreadyActive(String toEmail){
                final String username = "logariasmoi.nos@gmail.com";
		final String password = "admin123!";

		Properties props = new Properties();
		props.put("mail.smtp.auth", "true");
		props.put("mail.smtp.starttls.enable", "true");
		props.put("mail.smtp.host", "smtp.gmail.com");
		props.put("mail.smtp.port", "587");

		Session session = Session.getInstance(props,
		  new javax.mail.Authenticator() {
			protected PasswordAuthentication getPasswordAuthentication() {
				return new PasswordAuthentication(username, password);
			}
		  });

		try {

			Message message = new MimeMessage(session);
			message.setFrom(new InternetAddress("logariasmoi.nos@gmail.com"));
			message.setRecipients(Message.RecipientType.TO,
				InternetAddress.parse(toEmail));
			message.setSubject("Λογαριασμός Χρήστη");
			message.setText(" Το αίτημα απορίφθηκε. \n"
				+ "\n\n Έχετε ήδη ενεργό λογαριασμό."
                                
                                + "\n\n ΜΗΝ ΑΠΑΝΤΗΣΕΤΕ ΣΕ ΑΥΤΟ ΤΟ ΜΥΝΗΜΑ"
                                 );

			Transport.send(message);

			System.out.println("Done");

		} catch (MessagingException e) {
			throw new RuntimeException(e);
		}
    }
     
      void send_NonValid(String toEmail){
                final String username = "logariasmoi.nos@gmail.com";
		final String password = "admin123!";

		Properties props = new Properties();
		props.put("mail.smtp.auth", "true");
		props.put("mail.smtp.starttls.enable", "true");
		props.put("mail.smtp.host", "smtp.gmail.com");
		props.put("mail.smtp.port", "587");

		Session session = Session.getInstance(props,
		  new javax.mail.Authenticator() {
			protected PasswordAuthentication getPasswordAuthentication() {
				return new PasswordAuthentication(username, password);
			}
		  });

		try {

			Message message = new MimeMessage(session);
			message.setFrom(new InternetAddress("logariasmoi.nos@gmail.com"));
			message.setRecipients(Message.RecipientType.TO,
				InternetAddress.parse(toEmail));
			message.setSubject("Λογαριασμός Χρήστη");
			message.setText(" Το αίτημα απορίφθηκε. \n"
				+ "\n\n Δεν είστε καταχωριμένος ως νοσηλευτής στο σύστημα\n\n"
                                
                                + "\n\n ΜΗΝ ΑΠΑΝΤΗΣΕΤΕ ΣΕ ΑΥΤΟ ΤΟ ΜΥΝΗΜΑ"
                                 );

			Transport.send(message);

			System.out.println("Done");

		} catch (MessagingException e) {
			throw new RuntimeException(e);
		}
    }
     
    
}
