package org.libsdl.app;

import org.acra.ACRA;
import org.acra.ReportField;
import org.acra.ReportingInteractionMode;
import org.acra.annotation.ReportsCrashes;

import android.app.Application;

@ReportsCrashes(
        // need to set custom report fields to add APPLICATION_LOG file
        customReportContent = {
            ReportField.REPORT_ID,
            ReportField.APP_VERSION_CODE,
            ReportField.APP_VERSION_NAME,
            ReportField.ANDROID_VERSION,
            ReportField.STACK_TRACE,
            ReportField.AVAILABLE_MEM_SIZE,
            ReportField.USER_COMMENT,
            ReportField.CRASH_DUMP,        // make sure you're using 4ntoine-acra or pull request merged to acra
        },
        formKey = "",
        resDialogTitle = R.string.app_name,
        resDialogText = R.string.app_name,
        resDialogCommentPrompt = R.string.app_name, // required to show user comment field
        mode = ReportingInteractionMode.TOAST,
        resToastText = R.string.app_name,
        mailTo = MainApp.SUPPORT_EMAIL)

public class MainApp extends Application{
	
	public static final String SUPPORT_EMAIL = "pdpdds@naver.com";
	
	@Override
    public void onCreate() {
        super.onCreate();
        // The following line triggers the initialization of ACRA
        ACRA.init(this);
    }
}
