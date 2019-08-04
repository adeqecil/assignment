import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class ok extends JFrame implements ActionListener{
    JButton submit = new JButton("Submit");
    JTextField nama = new JTextField(8);
    JLabel nam = new JLabel("Name");

    public ok(){
        JPanel first = new JPanel(new FlowLayout());
        JPanel second = new JPanel(new FlowLayout());
        //first.setComponentOrientation(LEFT_TO_RIGHT);
        first.add(nam);
        first.add(nama);
        second.add(submit);
        submit.addActionListener(new ActionListener(){

            @Override
            public void actionPerformed(ActionEvent event){
                actionPerformedSubmit(event);
            }
        });
        add(first, BorderLayout.CENTER);
        add(second, BorderLayout.SOUTH);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
        pack();
    }

    public void actionPerformedSubmit(ActionEvent event){
        if(nama.getText().length() < 6){
            JOptionPane.showMessageDialog(null, "Nama minimal 6 karakter", "Info", JOptionPane.ERROR_MESSAGE);
        }
        else{
            JOptionPane.showMessageDialog(null, "Sukses sumbit", "Infor", JOptionPane.INFORMATION_MESSAGE);
        }
    }

    public static void main(String[] args){
        new ok();
    }
}
