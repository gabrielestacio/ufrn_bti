package Trabalho04.src.questao01;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JTextField;
import javax.swing.JTextArea;

import java.io.PrintStream;

public class WriteScreen extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					WriteScreen frame = new WriteScreen();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public WriteScreen() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		
		JTextArea writeTextArea = new JTextArea();
		writeTextArea.setBounds(10, 10, 416, 181);
		contentPane.add(writeTextArea);
		
		JButton saveButton = new JButton("Salvar");
		saveButton.setBounds(176, 201, 85, 21);
		saveButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String texto = writeTextArea.getText();
				
				try {
					PrintStream output = new PrintStream("saida.txt");
					
					output.print(texto);
					System.out.println(texto);
					output.close();
				}
				catch(Exception er){
					er.getStackTrace();
				}
			}
		});
		contentPane.add(saveButton);
		
		JButton backButton = new JButton("Voltar");
		backButton.setBounds(176, 232, 85, 21);
		backButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
			}
		});
		contentPane.setLayout(null);
		contentPane.add(backButton);
	}
}
