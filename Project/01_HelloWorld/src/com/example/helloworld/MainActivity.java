package com.example.helloworld;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.widget.TextView;

public class MainActivity extends Activity {

	static {
	      System.loadLibrary("HelloWorld"); 
	   }

	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //setContentView(R.layout.activity_main);
     // Create a TextView.
        TextView textView = new TextView(this);
        // Retrieve the text from native method getMessage()
        textView.setText(getMessage());
        setContentView(textView);

    }
    
    public native String getMessage();

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }
    
}
