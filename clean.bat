@for /r %%i in (
*.aps *.idb *.ncb *.obj *.pch *.sbr *.tmp *.pdb *.bsc *.ilk *.res *.manifest
*.sdf *.dep *.ipch *.tlog *.exp *.hpj *.mdp *.plg *.clw *.user *Log.htm
) do del /f /q "%%i"
@echo ������ɣ�
@pause>nul
