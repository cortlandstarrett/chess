package lichess.types;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

import com.google.gson.Gson;

public class APIException extends Exception {

	private static final long serialVersionUID = 1L;
	private static final Gson gson = new Gson();
	
	private int status = -1;

	public APIException(String message) {
		super(message);
		status = -1;
	}

	public APIException(String url, int statusCode, String responseBody) {
		super(String.format("%s: %d: %s", url, statusCode, gson.fromJson(responseBody, APIError.class).error));
		status = statusCode;
	}
	
	public APIException(Throwable cause) {
		super(cause);
		status = -1;
	}
	
	public int getStatus() {
		return status;
	}
	
	public String getError() {
		final var baos = new ByteArrayOutputStream();
		printStackTrace(new PrintStream(baos));
		return baos.toString();
	}

	private static final class APIError {
		private String error;
	}

}
