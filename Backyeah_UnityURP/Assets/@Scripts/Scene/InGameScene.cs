using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InGameScene : BaseScene
{
    protected override bool Init()
    {
        if (base.Init() == false)
            return false;

        // SceneType = Define.SceneType.InGameScene;
        
        StartCoroutine(CoWaitLoad());

        return true;
    }

    IEnumerator CoWaitLoad()
    {
        //while (Managers.DataManager.IsLoaded() == false)          
        
        yield return null;
    }
}
