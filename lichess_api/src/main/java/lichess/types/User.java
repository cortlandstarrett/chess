package lichess.types;

public class User {
	
	private String id = "";
	private String username = "";
	private UserTitle title;

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	public UserTitle getTitle() {
		return title;
	}

	public void setTitle(UserTitle title) {
		this.title = title;
	}
	
}
