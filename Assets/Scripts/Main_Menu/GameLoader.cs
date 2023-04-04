using UnityEngine;
using UnityEngine.SceneManagement;

public class GameLoader : MonoBehaviour
{
    public void LoadGame()
    {
        SceneManager.LoadScene("MainMenu");
    }
}
