<?xml version="1.0" encoding="UTF-8"?>
<?PowerDesigner AppLocale="UTF16" ID="{4FE865AA-9C75-46DD-88A8-716EFD5385C1}" Label="" LastModificationDate="1336407227" Name="Bomberman" Objects="120" Symbols="14" Target="C++" TargetLink="Reference" Type="{18112060-1A4B-11D1-83D9-444553540000}" signature="CLD_OBJECT_MODEL" version="15.1.0.2850"?>
<!-- Veuillez ne pas modifier ce fichier -->

<Model xmlns:a="attribute" xmlns:c="collection" xmlns:o="object">

<o:RootObject Id="o1">
<c:Children>
<o:Model Id="o2">
<a:ObjectID>4FE865AA-9C75-46DD-88A8-716EFD5385C1</a:ObjectID>
<a:Name>Bomberman</a:Name>
<a:Code>Bomberman</a:Code>
<a:CreationDate>1336393137</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336407023</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:PackageOptionsText>[FolderOptions]

[FolderOptions\Class Diagram Objects]
GenerationCheckModel=Yes
GenerationPath=
GenerationOptions=
GenerationTasks=
GenerationTargets=
GenerationSelections=</a:PackageOptionsText>
<a:ModelOptionsText>[ModelOptions]

[ModelOptions\Cld]
CaseSensitive=Yes
DisplayName=Yes
EnableTrans=No
EnableRequirements=No
ShowClss=No
DeftAttr=int
DeftMthd=int
DeftParm=int
DeftCont=
DomnDttp=Yes
DomnChck=No
DomnRule=No
SupportDelay=No
PreviewEditable=Yes
AutoRealize=No
DttpFullName=Yes
DeftClssAttrVisi=private
VBNetPreprocessingSymbols=
CSharpPreprocessingSymbols=

[ModelOptions\Cld\NamingOptionsTemplates]

[ModelOptions\Cld\ClssNamingOptions]

[ModelOptions\Cld\ClssNamingOptions\CLDPCKG]

[ModelOptions\Cld\ClssNamingOptions\CLDPCKG\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDPCKG\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDDOMN]

[ModelOptions\Cld\ClssNamingOptions\CLDDOMN\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDDOMN\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDCLASS]

[ModelOptions\Cld\ClssNamingOptions\CLDCLASS\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDCLASS\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDINTF]

[ModelOptions\Cld\ClssNamingOptions\CLDINTF\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDINTF\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDACTR]

[ModelOptions\Cld\ClssNamingOptions\UCDACTR\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDACTR\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDUCAS]

[ModelOptions\Cld\ClssNamingOptions\UCDUCAS\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDUCAS\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDOBJT]

[ModelOptions\Cld\ClssNamingOptions\SQDOBJT\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDOBJT\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDMSSG]

[ModelOptions\Cld\ClssNamingOptions\SQDMSSG\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDMSSG\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CPDCOMP]

[ModelOptions\Cld\ClssNamingOptions\CPDCOMP\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CPDCOMP\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDATTR]

[ModelOptions\Cld\ClssNamingOptions\CLDATTR\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDATTR\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDMETHOD]

[ModelOptions\Cld\ClssNamingOptions\CLDMETHOD\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDMETHOD\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDPARM]

[ModelOptions\Cld\ClssNamingOptions\CLDPARM\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDPARM\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPORT]

[ModelOptions\Cld\ClssNamingOptions\OOMPORT\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPORT\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPART]

[ModelOptions\Cld\ClssNamingOptions\OOMPART\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPART\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDASSC]

[ModelOptions\Cld\ClssNamingOptions\CLDASSC\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDASSC\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDASSC]

[ModelOptions\Cld\ClssNamingOptions\UCDASSC\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDASSC\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\GNRLLINK]

[ModelOptions\Cld\ClssNamingOptions\GNRLLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\GNRLLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RQLINK]

[ModelOptions\Cld\ClssNamingOptions\RQLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RQLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RLZSLINK]

[ModelOptions\Cld\ClssNamingOptions\RLZSLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RLZSLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DEPDLINK]

[ModelOptions\Cld\ClssNamingOptions\DEPDLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DEPDLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMACTV]

[ModelOptions\Cld\ClssNamingOptions\OOMACTV\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMACTV\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\ACDOBST]

[ModelOptions\Cld\ClssNamingOptions\ACDOBST\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\ACDOBST\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\STAT]

[ModelOptions\Cld\ClssNamingOptions\STAT\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\STAT\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDNODE]

[ModelOptions\Cld\ClssNamingOptions\DPDNODE\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDNODE\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDCMPI]

[ModelOptions\Cld\ClssNamingOptions\DPDCMPI\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDCMPI\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDASSC]

[ModelOptions\Cld\ClssNamingOptions\DPDASSC\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDASSC\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMVAR]

[ModelOptions\Cld\ClssNamingOptions\OOMVAR\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMVAR\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FILO]

[ModelOptions\Cld\ClssNamingOptions\FILO\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=&quot;\/:*?&lt;&gt;|&quot;
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FILO\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_. &quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMEOBJ]

[ModelOptions\Cld\ClssNamingOptions\FRMEOBJ\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMEOBJ\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMELNK]

[ModelOptions\Cld\ClssNamingOptions\FRMELNK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMELNK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DefaultClass]

[ModelOptions\Cld\ClssNamingOptions\DefaultClass\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DefaultClass\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Generate]

[ModelOptions\Generate\Cdm]
CheckModel=Yes
SaveLinks=Yes
NameToCode=No
Notation=2

[ModelOptions\Generate\Pdm]
CheckModel=Yes
SaveLinks=Yes
ORMapping=No
NameToCode=No
BuildTrgr=No
TablePrefix=
RefrUpdRule=RESTRICT
RefrDelRule=RESTRICT
IndxPKName=%TABLE%_PK
IndxAKName=%TABLE%_AK
IndxFKName=%REFR%_FK
IndxThreshold=
ColnFKName=%.3:PARENT%_%COLUMN%
ColnFKNameUse=No

[ModelOptions\Generate\Xsm]
CheckModel=Yes
SaveLinks=Yes
ORMapping=No
NameToCode=No</a:ModelOptionsText>
<c:ObjectLanguage>
<o:Shortcut Id="o3">
<a:ObjectID>BB177875-36CA-4958-951D-2E5C6FE13361</a:ObjectID>
<a:Name>C++</a:Name>
<a:Code>C++</a:Code>
<a:CreationDate>1336393137</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336393137</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:TargetStereotype/>
<a:TargetID>22FB523D-7E45-430F-8069-3A702CF3BE3C</a:TargetID>
<a:TargetClassID>1811206C-1A4B-11D1-83D9-444553540000</a:TargetClassID>
</o:Shortcut>
</c:ObjectLanguage>
<c:ClassDiagrams>
<o:ClassDiagram Id="o4">
<a:ObjectID>94F67D7A-7E0A-4591-9B5A-506DEED6423D</a:ObjectID>
<a:Name>jeu</a:Name>
<a:Code>jeu</a:Code>
<a:CreationDate>1336393137</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336407023</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:DisplayPreferences>[DisplayPreferences]

[DisplayPreferences\CLD]

[DisplayPreferences\General]
Adjust to text=Yes
Snap Grid=No
Constrain Labels=Yes
Display Grid=No
Show Page Delimiter=Yes
Grid size=0
Graphic unit=2
Window color=255, 255, 255
Background image=
Background mode=8
Watermark image=
Watermark mode=8
Show watermark on screen=No
Gradient mode=0
Gradient end color=255, 255, 255
Show Swimlane=No
SwimlaneVert=Yes
TreeVert=No
CompDark=0

[DisplayPreferences\Object]
Mode=0
Trunc Length=80
Word Length=80
Word Text=!&quot;&quot;#$%&amp;&#39;()*+,-./:;&lt;=&gt;?@[\]^_`{|}~
Shortcut IntIcon=Yes
Shortcut IntLoct=Yes
Shortcut IntFullPath=No
Shortcut IntLastPackage=Yes
Shortcut ExtIcon=Yes
Shortcut ExtLoct=No
Shortcut ExtFullPath=No
Shortcut ExtLastPackage=Yes
Shortcut ExtIncludeModl=Yes
EObjShowStrn=Yes
ExtendedObject.Comment=No
ExtendedObject.IconPicture=No
ExtendedObject_SymbolLayout=
ELnkShowStrn=Yes
ELnkShowName=Yes
ExtendedLink_SymbolLayout=
FileObject.Stereotype=No
FileObject.DisplayName=Yes
FileObject.LocationOrName=No
FileObject.IconPicture=No
FileObject.IconMode=Yes
FileObject_SymbolLayout=
PckgShowStrn=Yes
Package.Comment=No
Package.IconPicture=No
Package_SymbolLayout=
Display Model Version=Yes
Class.IconPicture=No
Class_SymbolLayout=
Interface.IconPicture=No
Interface_SymbolLayout=
Port.IconPicture=No
Port_SymbolLayout=
ClssShowSttr=Yes
Class.Comment=No
ClssShowCntr=Yes
ClssShowAttr=Yes
ClssAttrTrun=No
ClssAttrMax=3
ClssShowMthd=Yes
ClssMthdTrun=No
ClssMthdMax=3
ClssShowInnr=Yes
IntfShowSttr=Yes
Interface.Comment=No
IntfShowAttr=Yes
IntfAttrTrun=No
IntfAttrMax=3
IntfShowMthd=Yes
IntfMthdTrun=No
IntfMthdMax=3
IntfShowCntr=Yes
IntfShowInnr=Yes
PortShowName=Yes
PortShowType=No
PortShowMult=No
AttrShowVisi=Yes
AttrVisiFmt=1
AttrShowStrn=Yes
AttrShowDttp=Yes
AttrShowDomn=No
AttrShowInit=Yes
MthdShowVisi=Yes
MthdVisiFmt=1
MthdShowStrn=Yes
MthdShowRttp=Yes
MthdShowParm=Yes
AsscShowName=No
AsscShowCntr=Yes
AsscShowRole=Yes
AsscShowOrdr=Yes
AsscShowMult=Yes
AsscMultStr=Yes
AsscShowStrn=No
GnrlShowName=No
GnrlShowStrn=Yes
GnrlShowCntr=Yes
RlzsShowName=No
RlzsShowStrn=Yes
RlzsShowCntr=Yes
DepdShowName=No
DepdShowStrn=Yes
DepdShowCntr=Yes
RqlkShowName=No
RqlkShowStrn=Yes
RqlkShowCntr=Yes

[DisplayPreferences\Symbol]

[DisplayPreferences\Symbol\FRMEOBJ]
STRNFont=Arial,8,N
STRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
LABLFont=Arial,8,N
LABLFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=6000
Height=2000
Brush color=255 255 255
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=64
Brush gradient color=192 192 192
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 255 128 128
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\FRMELNK]
CENTERFont=Arial,8,N
CENTERFont color=0, 0, 0
Line style=2
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 128 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\FILO]
OBJSTRNFont=Arial,8,N
OBJSTRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
LCNMFont=Arial,8,N
LCNMFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=Yes
Keep center=Yes
Keep size=No
Width=2400
Height=2400
Brush color=255 255 255
Fill Color=No
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 0 0 255
Shadow color=192 192 192
Shadow=-1

[DisplayPreferences\Symbol\CLDPCKG]
STRNFont=Arial,8,N
STRNFont color=0 0 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
LABLFont=Arial,8,N
LABLFont color=0 0 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4800
Height=3600
Brush color=255 255 192
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 178 178 178
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDCLASS]
STRNFont=Arial,8,N
STRNFont color=0 0 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
CNTRFont=Arial,8,N
CNTRFont color=0 0 0
AttributesFont=Arial,8,N
AttributesFont color=0 0 0
ClassPrimaryAttributeFont=Arial,8,U
ClassPrimaryAttributeFont color=0 0 0
OperationsFont=Arial,8,N
OperationsFont color=0 0 0
InnerClassifiersFont=Arial,8,N
InnerClassifiersFont color=0 0 0
LABLFont=Arial,8,N
LABLFont color=0 0 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4800
Height=3600
Brush color=233 202 131
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 0 0
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDINTF]
STRNFont=Arial,8,N
STRNFont color=0 0 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
CNTRFont=Arial,8,N
CNTRFont color=0 0 0
AttributesFont=Arial,8,N
AttributesFont color=0 0 0
OperationsFont=Arial,8,N
OperationsFont color=0 0 0
InnerClassifiersFont=Arial,8,N
InnerClassifiersFont color=0 0 0
LABLFont=Arial,8,N
LABLFont color=0 0 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4800
Height=3600
Brush color=205 156 156
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 0 0
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\OOMPORT]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
AutoAdjustToText=No
Keep aspect=No
Keep center=No
Keep size=No
Width=825
Height=800
Brush color=250 241 211
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 64 0
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDASSC]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
MULAFont=Arial,8,N
MULAFont color=0 0 0
Line style=2
Pen=1 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\INNERLINK]
Line style=2
Pen=1 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDACLK]
Line style=2
Pen=2 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\GNRLLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
Line style=2
Pen=1 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\RLZSLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
Line style=2
Pen=3 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\RQLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
Line style=2
Pen=1 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\DEPDLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
Line style=2
Pen=2 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\USRDEPD]
OBJXSTRFont=Arial,8,N
OBJXSTRFont color=0 0 0
Line style=2
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=2 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\Free Symbol]
Free TextFont=Arial,8,N
Free TextFont color=0 0 0
Line style=2
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 64 0
Shadow color=192 192 192
Shadow=0</a:DisplayPreferences>
<a:PaperSize>(8267, 11692)</a:PaperSize>
<a:PageMargins>((315,354), (433,354))</a:PageMargins>
<a:PageOrientation>1</a:PageOrientation>
<a:PaperSource>15</a:PaperSource>
<c:Symbols>
<o:GeneralizationSymbol Id="o5">
<a:CreationDate>1336403708</a:CreationDate>
<a:ModificationDate>1336404662</a:ModificationDate>
<a:Rect>((-1012,-13624), (3787,12657))</a:Rect>
<a:ListOfPoints>((3787,-13624),(3787,1334),(-1012,1334),(-1012,12657))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o6"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o7"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o8"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o9">
<a:CreationDate>1336404356</a:CreationDate>
<a:ModificationDate>1336404912</a:ModificationDate>
<a:Rect>((-1012,12657), (20663,33225))</a:Rect>
<a:ListOfPoints>((20663,33225),(20663,12657),(-1012,12657))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o10"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o7"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o11"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o12">
<a:CreationDate>1336404847</a:CreationDate>
<a:ModificationDate>1336404900</a:ModificationDate>
<a:Rect>((-12634,12657), (-1012,33337))</a:Rect>
<a:ListOfPoints>((-12634,33337),(-12634,23909),(-1012,23909),(-1012,12657))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o13"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o7"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o14"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o15">
<a:CreationDate>1336405083</a:CreationDate>
<a:ModificationDate>1336406260</a:ModificationDate>
<a:Rect>((-1173,9897), (57049,30150))</a:Rect>
<a:ListOfPoints>((57049,30150),(57049,9897),(-1173,9897))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o16"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o7"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o17"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o18">
<a:CreationDate>1336406717</a:CreationDate>
<a:ModificationDate>1336406812</a:ModificationDate>
<a:Rect>((3937,-41493), (32530,-13474))</a:Rect>
<a:ListOfPoints>((32530,-41493),(32530,-13474),(3937,-13474))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o19"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o6"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o20"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o21">
<a:CreationDate>1336406819</a:CreationDate>
<a:ModificationDate>1336407030</a:ModificationDate>
<a:Rect>((-9096,-42169), (3937,-13474))</a:Rect>
<a:ListOfPoints>((-9096,-42169),(-9096,-31960),(3937,-31960),(3937,-13474))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o22"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o6"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o23"/>
</c:Object>
</o:GeneralizationSymbol>
<o:ClassSymbol Id="o7">
<a:CreationDate>1336401814</a:CreationDate>
<a:ModificationDate>1336404108</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-12712,6489), (10688,18825))</a:Rect>
<a:AutoAdjustToText>0</a:AutoAdjustToText>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<a:ManuallyResized>1</a:ManuallyResized>
<c:Object>
<o:Class Ref="o24"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o6">
<a:CreationDate>1336403160</a:CreationDate>
<a:ModificationDate>1336404662</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-12795,-25125), (20369,-2123))</a:Rect>
<a:AutoAdjustToText>0</a:AutoAdjustToText>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<a:ManuallyResized>1</a:ManuallyResized>
<c:Object>
<o:Class Ref="o25"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o10">
<a:CreationDate>1336404353</a:CreationDate>
<a:ModificationDate>1336404912</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((5124,28881), (36202,37569))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o26"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o13">
<a:CreationDate>1336404840</a:CreationDate>
<a:ModificationDate>1336404842</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-28211,28993), (2943,37681))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o27"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o16">
<a:CreationDate>1336405060</a:CreationDate>
<a:ModificationDate>1336406250</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((40549,22885), (73557,37417))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o28"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o19">
<a:CreationDate>1336406694</a:CreationDate>
<a:ModificationDate>1336406806</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((26570,-43404), (38490,-39583))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o29"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o22">
<a:CreationDate>1336406696</a:CreationDate>
<a:ModificationDate>1336407030</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-15056,-44079), (-3136,-40259))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o30"/>
</c:Object>
</o:ClassSymbol>
</c:Symbols>
</o:ClassDiagram>
<o:ClassDiagram Id="o31">
<a:ObjectID>DA12F656-39C2-4EFF-88C8-84D86B1D436E</a:ObjectID>
<a:Name>Menu</a:Name>
<a:Code>Menu</a:Code>
<a:CreationDate>1336393191</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336393195</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:DisplayPreferences>[DisplayPreferences]

[DisplayPreferences\CLD]

[DisplayPreferences\General]
Adjust to text=Yes
Snap Grid=No
Constrain Labels=Yes
Display Grid=No
Show Page Delimiter=Yes
Grid size=0
Graphic unit=2
Window color=255, 255, 255
Background image=
Background mode=8
Watermark image=
Watermark mode=8
Show watermark on screen=No
Gradient mode=0
Gradient end color=255, 255, 255
Show Swimlane=No
SwimlaneVert=Yes
TreeVert=No
CompDark=0

[DisplayPreferences\Object]
Mode=0
Trunc Length=80
Word Length=80
Word Text=!&quot;&quot;#$%&amp;&#39;()*+,-./:;&lt;=&gt;?@[\]^_`{|}~
Shortcut IntIcon=Yes
Shortcut IntLoct=Yes
Shortcut IntFullPath=No
Shortcut IntLastPackage=Yes
Shortcut ExtIcon=Yes
Shortcut ExtLoct=No
Shortcut ExtFullPath=No
Shortcut ExtLastPackage=Yes
Shortcut ExtIncludeModl=Yes
EObjShowStrn=Yes
ExtendedObject.Comment=No
ExtendedObject.IconPicture=No
ExtendedObject_SymbolLayout=
ELnkShowStrn=Yes
ELnkShowName=Yes
ExtendedLink_SymbolLayout=
FileObject.Stereotype=No
FileObject.DisplayName=Yes
FileObject.LocationOrName=No
FileObject.IconPicture=No
FileObject.IconMode=Yes
FileObject_SymbolLayout=
PckgShowStrn=Yes
Package.Comment=No
Package.IconPicture=No
Package_SymbolLayout=
Display Model Version=Yes
Class.IconPicture=No
Class_SymbolLayout=
Interface.IconPicture=No
Interface_SymbolLayout=
Port.IconPicture=No
Port_SymbolLayout=
ClssShowSttr=Yes
Class.Comment=No
ClssShowCntr=Yes
ClssShowAttr=Yes
ClssAttrTrun=No
ClssAttrMax=3
ClssShowMthd=Yes
ClssMthdTrun=No
ClssMthdMax=3
ClssShowInnr=Yes
IntfShowSttr=Yes
Interface.Comment=No
IntfShowAttr=Yes
IntfAttrTrun=No
IntfAttrMax=3
IntfShowMthd=Yes
IntfMthdTrun=No
IntfMthdMax=3
IntfShowCntr=Yes
IntfShowInnr=Yes
PortShowName=Yes
PortShowType=No
PortShowMult=No
AttrShowVisi=Yes
AttrVisiFmt=1
AttrShowStrn=Yes
AttrShowDttp=Yes
AttrShowDomn=No
AttrShowInit=Yes
MthdShowVisi=Yes
MthdVisiFmt=1
MthdShowStrn=Yes
MthdShowRttp=Yes
MthdShowParm=Yes
AsscShowName=No
AsscShowCntr=Yes
AsscShowRole=Yes
AsscShowOrdr=Yes
AsscShowMult=Yes
AsscMultStr=Yes
AsscShowStrn=No
GnrlShowName=No
GnrlShowStrn=Yes
GnrlShowCntr=Yes
RlzsShowName=No
RlzsShowStrn=Yes
RlzsShowCntr=Yes
DepdShowName=No
DepdShowStrn=Yes
DepdShowCntr=Yes
RqlkShowName=No
RqlkShowStrn=Yes
RqlkShowCntr=Yes

[DisplayPreferences\Symbol]

[DisplayPreferences\Symbol\FRMEOBJ]
STRNFont=Arial,8,N
STRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
LABLFont=Arial,8,N
LABLFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=6000
Height=2000
Brush color=255 255 255
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=64
Brush gradient color=192 192 192
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 255 128 128
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\FRMELNK]
CENTERFont=Arial,8,N
CENTERFont color=0, 0, 0
Line style=2
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 128 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\FILO]
OBJSTRNFont=Arial,8,N
OBJSTRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
LCNMFont=Arial,8,N
LCNMFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=Yes
Keep center=Yes
Keep size=No
Width=2400
Height=2400
Brush color=255 255 255
Fill Color=No
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 0 0 255
Shadow color=192 192 192
Shadow=-1

[DisplayPreferences\Symbol\CLDPCKG]
STRNFont=Arial,8,N
STRNFont color=0 0 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
LABLFont=Arial,8,N
LABLFont color=0 0 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4800
Height=3600
Brush color=255 255 192
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 178 178 178
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDCLASS]
STRNFont=Arial,8,N
STRNFont color=0 0 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
CNTRFont=Arial,8,N
CNTRFont color=0 0 0
AttributesFont=Arial,8,N
AttributesFont color=0 0 0
ClassPrimaryAttributeFont=Arial,8,U
ClassPrimaryAttributeFont color=0 0 0
OperationsFont=Arial,8,N
OperationsFont color=0 0 0
InnerClassifiersFont=Arial,8,N
InnerClassifiersFont color=0 0 0
LABLFont=Arial,8,N
LABLFont color=0 0 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4800
Height=3600
Brush color=233 202 131
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 0 0
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDINTF]
STRNFont=Arial,8,N
STRNFont color=0 0 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
CNTRFont=Arial,8,N
CNTRFont color=0 0 0
AttributesFont=Arial,8,N
AttributesFont color=0 0 0
OperationsFont=Arial,8,N
OperationsFont color=0 0 0
InnerClassifiersFont=Arial,8,N
InnerClassifiersFont color=0 0 0
LABLFont=Arial,8,N
LABLFont color=0 0 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4800
Height=3600
Brush color=205 156 156
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 0 0
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\OOMPORT]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
AutoAdjustToText=No
Keep aspect=No
Keep center=No
Keep size=No
Width=825
Height=800
Brush color=250 241 211
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 64 0
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDASSC]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
MULAFont=Arial,8,N
MULAFont color=0 0 0
Line style=2
Pen=1 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\INNERLINK]
Line style=2
Pen=1 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDACLK]
Line style=2
Pen=2 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\GNRLLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
Line style=2
Pen=1 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\RLZSLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
Line style=2
Pen=3 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\RQLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
Line style=2
Pen=1 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\DEPDLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
Line style=2
Pen=2 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\USRDEPD]
OBJXSTRFont=Arial,8,N
OBJXSTRFont color=0 0 0
Line style=2
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=2 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\Free Symbol]
Free TextFont=Arial,8,N
Free TextFont color=0 0 0
Line style=2
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 64 0
Shadow color=192 192 192
Shadow=0</a:DisplayPreferences>
<a:PaperSize>(8267, 11692)</a:PaperSize>
<a:PageMargins>((315,354), (433,354))</a:PageMargins>
<a:PageOrientation>1</a:PageOrientation>
<a:PaperSource>15</a:PaperSource>
</o:ClassDiagram>
</c:ClassDiagrams>
<c:DefaultDiagram>
<o:ClassDiagram Ref="o4"/>
</c:DefaultDiagram>
<c:Classes>
<o:Class Id="o24">
<a:ObjectID>983B77AF-A9A8-433D-B9EB-E5249CAB763A</a:ObjectID>
<a:Name>AObj</a:Name>
<a:Code>AObj</a:Code>
<a:CreationDate>1336401814</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336405090</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<a:Classifier.Abstract>1</a:Classifier.Abstract>
<c:Attributes>
<o:Attribute Id="o32">
<a:ObjectID>434AA632-B8F3-441B-9A8E-9A23B8E22B33</a:ObjectID>
<a:Name>_pos</a:Name>
<a:Code>_pos</a:Code>
<a:CreationDate>1336402574</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336402621</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:DataType>Point</a:DataType>
<a:Attribute.Visibility>#</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o33">
<a:ObjectID>8AA67C3B-3A48-489E-AE65-9C76AE8B66CF</a:ObjectID>
<a:Name>initialize</a:Name>
<a:Code>initialize</a:Code>
<a:CreationDate>1336402621</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336407227</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o34">
<a:ObjectID>5F70F530-F314-4664-9A93-6AF2B5845AE4</a:ObjectID>
<a:Name>draw</a:Name>
<a:Code>draw</a:Code>
<a:CreationDate>1336402667</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336407227</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o35">
<a:ObjectID>EA301541-7899-4CDB-8CC3-951D1C36AEAE</a:ObjectID>
<a:Name>clock</a:Name>
<a:Code>clock</a:Code>
<a:CreationDate>1336402752</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336402833</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>gdl::GameClock const&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o36">
<a:ObjectID>E0CCE4CB-BFBB-4639-846F-5D6D223997FB</a:ObjectID>
<a:Name>input</a:Name>
<a:Code>input</a:Code>
<a:CreationDate>1336402796</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336402833</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>gdl::Input&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o37">
<a:ObjectID>05CDE8E2-36CF-4E50-BBA7-7B7685978BC6</a:ObjectID>
<a:Name>update</a:Name>
<a:Code>update</a:Code>
<a:CreationDate>1336402685</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336407227</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o38">
<a:ObjectID>BBFEF89C-DD50-4E62-9E52-BDA806A426FC</a:ObjectID>
<a:Name>AObj</a:Name>
<a:Code>AObj</a:Code>
<a:CreationDate>1336403957</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403991</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Constructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Class Ref="o24"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o39">
<a:ObjectID>48305C97-2DB8-4969-B64D-9E879DB9D1FD</a:ObjectID>
<a:Name>~AObj</a:Name>
<a:Code>~AObj</a:Code>
<a:CreationDate>1336403957</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403991</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Destructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Class Ref="o24"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o40">
<a:ObjectID>0267D17C-ACF7-4ED1-AC18-D16CF570B6E7</a:ObjectID>
<a:Name>AObj</a:Name>
<a:Code>AObj</a:Code>
<a:CreationDate>1336403980</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403991</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Copy constructor</a:Stereotype>
<a:Operation.Visibility>-</a:Operation.Visibility>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o41">
<a:ObjectID>CBCFF57B-95D4-418A-A02C-E4660DC03EB6</a:ObjectID>
<a:Name>oldAObj</a:Name>
<a:Code>oldAObj</a:Code>
<a:CreationDate>1336403980</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403991</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>const AObj&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
<c:ObjectDataType>
<o:Class Ref="o24"/>
</c:ObjectDataType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Class Ref="o24"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o42">
<a:ObjectID>B33C9A97-B075-4D38-A037-407BBE9534C3</a:ObjectID>
<a:Name>Duplicate</a:Name>
<a:Code>Duplicate</a:Code>
<a:CreationDate>1336403982</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403991</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Duplicate</a:Stereotype>
<a:ReturnType>AObj</a:ReturnType>
<a:Operation.Visibility>-</a:Operation.Visibility>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:ObjectReturnType>
<o:Class Ref="o24"/>
</c:ObjectReturnType>
<c:InfluentObject>
<o:Class Ref="o24"/>
</c:InfluentObject>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o25">
<a:ObjectID>81EAEA6B-B6B4-49FF-B068-5267BA8D8F91</a:ObjectID>
<a:Name>APlayer</a:Name>
<a:Code>APlayer</a:Code>
<a:CreationDate>1336403160</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336407023</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<a:Classifier.Abstract>1</a:Classifier.Abstract>
<c:Attributes>
<o:Attribute Id="o43">
<a:ObjectID>04BE58D5-8F2F-4BFC-A145-F4148AA2133F</a:ObjectID>
<a:Name>_pv</a:Name>
<a:Code>_pv</a:Code>
<a:CreationDate>1336403171</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403624</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:DataType>int</a:DataType>
<a:Attribute.Visibility>#</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o44">
<a:ObjectID>999B5C6A-38DF-45D8-A3D2-BA9E7E033C91</a:ObjectID>
<a:Name>_weapon</a:Name>
<a:Code>_weapon</a:Code>
<a:CreationDate>1336403171</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403624</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:DataType>eBomb</a:DataType>
<a:Attribute.Visibility>#</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o45">
<a:ObjectID>F4CD9DD3-E5CB-4345-B9B5-C34EC091858A</a:ObjectID>
<a:Name>_skin</a:Name>
<a:Code>_skin</a:Code>
<a:CreationDate>1336403171</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403624</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:DataType>eSkin</a:DataType>
<a:Attribute.Visibility>#</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o46">
<a:ObjectID>D6DAD55B-4A93-45B2-82DB-5FCCEF4D8A4A</a:ObjectID>
<a:Name>_team</a:Name>
<a:Code>_team</a:Code>
<a:CreationDate>1336403171</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403624</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:DataType>size_t</a:DataType>
<a:Attribute.Visibility>#</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o47">
<a:ObjectID>DE929DCB-89FB-434D-B2D1-995D09F7417F</a:ObjectID>
<a:Name>_id</a:Name>
<a:Code>_id</a:Code>
<a:CreationDate>1336403171</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403624</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:DataType>size_t</a:DataType>
<a:Attribute.Visibility>#</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o48">
<a:ObjectID>16EC61A5-9C2C-4E6A-BE0C-B0AA0F7729E8</a:ObjectID>
<a:Name>_state</a:Name>
<a:Code>_state</a:Code>
<a:CreationDate>1336403171</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403624</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:DataType>eState</a:DataType>
<a:Attribute.Visibility>#</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o49">
<a:ObjectID>88C90B62-23D4-4E4E-B5C6-7308DA38E349</a:ObjectID>
<a:Name>_bombEffect</a:Name>
<a:Code>_bombEffect</a:Code>
<a:CreationDate>1336403171</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403624</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:DataType>std::map&lt;eBomb, fBomb&gt;</a:DataType>
<a:Attribute.Visibility>#</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o50">
<a:ObjectID>C2CA0B98-AA9D-402A-9951-DC2819E43B4D</a:ObjectID>
<a:Name>_bonusEffect</a:Name>
<a:Code>_bonusEffect</a:Code>
<a:CreationDate>1336403171</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403624</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:DataType>std::map&lt;eBonus, fBonus&gt;</a:DataType>
<a:Attribute.Visibility>#</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o51">
<a:ObjectID>9A0C3E98-B9DA-4A69-99AA-A89652C2FECA</a:ObjectID>
<a:Name>_model</a:Name>
<a:Code>_model</a:Code>
<a:CreationDate>1336403708</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403872</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:DataType>gdl::Model</a:DataType>
<a:Attribute.Visibility>#</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o52">
<a:ObjectID>F8244F17-BEC7-41B3-BB15-497672E26F9D</a:ObjectID>
<a:Name>_name</a:Name>
<a:Code>_name</a:Code>
<a:CreationDate>1336404118</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404294</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:DataType>std::string</a:DataType>
<a:Attribute.Visibility>#</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o53">
<a:ObjectID>87441A85-4E62-42E2-8B09-6880D60FB0E4</a:ObjectID>
<a:Name>play</a:Name>
<a:Code>play</a:Code>
<a:CreationDate>1336403624</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403708</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o54">
<a:ObjectID>019ACC73-19AA-448B-AEAC-04A68990D33C</a:ObjectID>
<a:Name>takeDamage</a:Name>
<a:Code>takeDamage</a:Code>
<a:CreationDate>1336403624</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403872</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o55">
<a:ObjectID>1B1907BD-DF44-43BF-A447-074DEBEA4A9D</a:ObjectID>
<a:Name>origin</a:Name>
<a:Code>origin</a:Code>
<a:CreationDate>1336403708</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403752</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>Point</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o56">
<a:ObjectID>BB98B7B3-D395-4CED-8175-C963B7EFC6AF</a:ObjectID>
<a:Name>pattern</a:Name>
<a:Code>pattern</a:Code>
<a:CreationDate>1336403708</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403752</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>Pattern</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o57">
<a:ObjectID>FB7A95C3-C367-4C5E-8CA9-94883FEE9543</a:ObjectID>
<a:Name>initialize</a:Name>
<a:Code>initialize</a:Code>
<a:CreationDate>1336403797</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403797</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Override</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o33"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o58">
<a:ObjectID>337C80F8-7959-412D-A99D-84CE2491B395</a:ObjectID>
<a:Name>draw</a:Name>
<a:Code>draw</a:Code>
<a:CreationDate>1336403797</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403797</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Override</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o59">
<a:ObjectID>E7E811FB-39E2-4865-AF68-6509422254E3</a:ObjectID>
<a:Name>clock</a:Name>
<a:Code>clock</a:Code>
<a:CreationDate>1336403797</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403797</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>gdl::GameClock const&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o60">
<a:ObjectID>120B367D-6A89-4E2D-ADC4-4B89F232E0BB</a:ObjectID>
<a:Name>input</a:Name>
<a:Code>input</a:Code>
<a:CreationDate>1336403797</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403797</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>gdl::Input&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Operation Ref="o34"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o61">
<a:ObjectID>42101384-C9BA-436F-93C1-AE2DA95655A1</a:ObjectID>
<a:Name>update</a:Name>
<a:Code>update</a:Code>
<a:CreationDate>1336403797</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403797</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Override</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o37"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o62">
<a:ObjectID>04E98B52-AABF-408B-86DE-DEEB6268B188</a:ObjectID>
<a:Name>APlayer</a:Name>
<a:Code>APlayer</a:Code>
<a:CreationDate>1336404083</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404292</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Constructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o63">
<a:ObjectID>8D9EF38A-051B-4F05-BB67-173307838ACF</a:ObjectID>
<a:Name>name</a:Name>
<a:Code>name</a:Code>
<a:CreationDate>1336404268</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404292</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>std::string const&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o64">
<a:ObjectID>7967567E-D360-45CF-991E-8B4318211CB8</a:ObjectID>
<a:Name>~APlayer</a:Name>
<a:Code>~APlayer</a:Code>
<a:CreationDate>1336404083</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404093</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Destructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o65">
<a:ObjectID>69CF89BE-EDEA-4C8F-87CB-38BBC0745BFA</a:ObjectID>
<a:Name>APlayer</a:Name>
<a:Code>APlayer</a:Code>
<a:CreationDate>1336404083</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404093</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Copy constructor</a:Stereotype>
<a:Operation.Visibility>-</a:Operation.Visibility>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o66">
<a:ObjectID>0EC5C461-86E1-4360-A35B-BE22542B8C86</a:ObjectID>
<a:Name>oldAPlayer</a:Name>
<a:Code>oldAPlayer</a:Code>
<a:CreationDate>1336404083</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404093</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>const APlayer&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
<c:ObjectDataType>
<o:Class Ref="o25"/>
</c:ObjectDataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o67">
<a:ObjectID>622985EF-F075-4F3C-A4F6-01F6C26C973D</a:ObjectID>
<a:Name>Duplicate</a:Name>
<a:Code>Duplicate</a:Code>
<a:CreationDate>1336404083</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404093</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Duplicate</a:Stereotype>
<a:ReturnType>APlayer</a:ReturnType>
<a:Operation.Visibility>-</a:Operation.Visibility>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:ObjectReturnType>
<o:Class Ref="o25"/>
</c:ObjectReturnType>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o26">
<a:ObjectID>E745BFDC-1988-4208-B1E2-A867D238DAA5</a:ObjectID>
<a:Name>Bomb</a:Name>
<a:Code>Bomb</a:Code>
<a:CreationDate>1336404353</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404467</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o68">
<a:ObjectID>E990696E-C9F5-410F-9A4E-74FF6788989A</a:ObjectID>
<a:Name>_type</a:Name>
<a:Code>_type</a:Code>
<a:CreationDate>1336404356</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404467</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:DataType>eBomb</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o69">
<a:ObjectID>1535D625-35E1-4F74-8DFF-523F023BF8D8</a:ObjectID>
<a:Name>get_type</a:Name>
<a:Code>get_type</a:Code>
<a:CreationDate>1336404422</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404533</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>eBomb</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<a:Readonly>1</a:Readonly>
<c:InfluentObject>
<o:Attribute Ref="o68"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o70">
<a:ObjectID>F0C16F5B-78D6-448E-921D-D31529461AC0</a:ObjectID>
<a:Name>Bomb</a:Name>
<a:Code>Bomb</a:Code>
<a:CreationDate>1336404461</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404480</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Constructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o71">
<a:ObjectID>4B9B327B-A901-44FE-AB97-107D05E2545D</a:ObjectID>
<a:Name>t</a:Name>
<a:Code>t</a:Code>
<a:CreationDate>1336404467</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404480</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>eBomb</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Class Ref="o26"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o72">
<a:ObjectID>251CD208-299E-4CB0-BED7-0BF6C4FC760F</a:ObjectID>
<a:Name>~Bomb</a:Name>
<a:Code>~Bomb</a:Code>
<a:CreationDate>1336404461</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404467</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Destructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Class Ref="o26"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o73">
<a:ObjectID>F16846B3-FAC0-4079-9DA0-C0E334DA6566</a:ObjectID>
<a:Name>initialize</a:Name>
<a:Code>initialize</a:Code>
<a:CreationDate>1336404453</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404453</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Override</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o33"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o74">
<a:ObjectID>B20702FB-E889-46A4-BB08-5884C6C088D8</a:ObjectID>
<a:Name>draw</a:Name>
<a:Code>draw</a:Code>
<a:CreationDate>1336404453</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404453</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Override</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o75">
<a:ObjectID>C43D2BD3-E685-437D-93B5-A3B9B4EA601B</a:ObjectID>
<a:Name>clock</a:Name>
<a:Code>clock</a:Code>
<a:CreationDate>1336404453</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404453</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>gdl::GameClock const&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o76">
<a:ObjectID>0E256832-7AB4-42E0-BED4-FA25592A191E</a:ObjectID>
<a:Name>input</a:Name>
<a:Code>input</a:Code>
<a:CreationDate>1336404453</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404453</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>gdl::Input&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Operation Ref="o34"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o77">
<a:ObjectID>A88F56DF-28E4-435C-8C1D-0769D329F749</a:ObjectID>
<a:Name>update</a:Name>
<a:Code>update</a:Code>
<a:CreationDate>1336404453</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404453</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Override</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o37"/>
</c:InfluentObject>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o27">
<a:ObjectID>B0E9B4DA-59F7-4FF9-8C39-63E69DE5CECF</a:ObjectID>
<a:Name>Bonus</a:Name>
<a:Code>Bonus</a:Code>
<a:CreationDate>1336404840</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404900</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o78">
<a:ObjectID>8645AD14-AD78-4D2D-9815-6E219FBBD4EC</a:ObjectID>
<a:Name>_type</a:Name>
<a:Code>_type</a:Code>
<a:CreationDate>1336404840</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404900</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:DataType>eBonus</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o79">
<a:ObjectID>13B8EA22-6A63-4689-A6CC-589B6765D04A</a:ObjectID>
<a:Name>get_type</a:Name>
<a:Code>get_type</a:Code>
<a:CreationDate>1336404840</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404900</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Getter</a:Stereotype>
<a:ReturnType>eBonus</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<a:Readonly>1</a:Readonly>
<c:InfluentObject>
<o:Attribute Ref="o78"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o80">
<a:ObjectID>6C510EFC-104B-4B32-927A-A4FB391494B0</a:ObjectID>
<a:Name>Bonus</a:Name>
<a:Code>Bonus</a:Code>
<a:CreationDate>1336404840</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404900</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Constructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o81">
<a:ObjectID>B2979C41-170C-400D-B4D4-8114E1B17389</a:ObjectID>
<a:Name>t</a:Name>
<a:Code>t</a:Code>
<a:CreationDate>1336404840</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404840</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>eBomb</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Class Ref="o27"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o82">
<a:ObjectID>C759A69F-0220-4A83-B410-B0EA7113C187</a:ObjectID>
<a:Name>~Bonus</a:Name>
<a:Code>~Bonus</a:Code>
<a:CreationDate>1336404840</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404900</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Destructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Class Ref="o27"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o83">
<a:ObjectID>5B42A41A-509A-40B5-A7DA-A43DC952C3DE</a:ObjectID>
<a:Name>initialize</a:Name>
<a:Code>initialize</a:Code>
<a:CreationDate>1336404840</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404840</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Override</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o84">
<a:ObjectID>24915753-E80D-4348-955A-2A5490571DEF</a:ObjectID>
<a:Name>draw</a:Name>
<a:Code>draw</a:Code>
<a:CreationDate>1336404840</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404840</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Override</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o85">
<a:ObjectID>49998269-6842-41D3-9A67-023310F407E4</a:ObjectID>
<a:Name>clock</a:Name>
<a:Code>clock</a:Code>
<a:CreationDate>1336404840</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404840</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>gdl::GameClock const&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o86">
<a:ObjectID>80839F11-9631-4EF1-81BA-E437E3C5D204</a:ObjectID>
<a:Name>input</a:Name>
<a:Code>input</a:Code>
<a:CreationDate>1336404840</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404840</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>gdl::Input&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o87">
<a:ObjectID>13424DE8-FDF9-434F-8459-CDE202C121BE</a:ObjectID>
<a:Name>update</a:Name>
<a:Code>update</a:Code>
<a:CreationDate>1336404840</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404840</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Override</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o28">
<a:ObjectID>BCD17F71-069E-4255-A983-2E8A7C9A99F6</a:ObjectID>
<a:Name>Map</a:Name>
<a:Code>Map</a:Code>
<a:CreationDate>1336405060</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336406248</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o88">
<a:ObjectID>CDAB3F35-5473-48F3-B313-945FFFB22DAC</a:ObjectID>
<a:Name>_map</a:Name>
<a:Code>_map</a:Code>
<a:CreationDate>1336405090</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336405217</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:DataType>std::string</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o89">
<a:ObjectID>638F0B43-5089-41D1-9BCA-59370841F3EB</a:ObjectID>
<a:Name>_x</a:Name>
<a:Code>_x</a:Code>
<a:CreationDate>1336405967</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336406248</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:DataType>size_t</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o90">
<a:ObjectID>D9CC4548-84BD-4C19-910C-EDA02168B401</a:ObjectID>
<a:Name>_y</a:Name>
<a:Code>_y</a:Code>
<a:CreationDate>1336405967</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336406248</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:DataType>size_t</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o91">
<a:ObjectID>D4BC3D55-D61E-45D5-AEE1-58796D681831</a:ObjectID>
<a:Name>Attribut_4</a:Name>
<a:Code>Attribut_4</a:Code>
<a:CreationDate>1336405967</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336406248</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:DataType>int</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o92">
<a:ObjectID>E99E9C99-A47A-436B-B7A9-14792971783D</a:ObjectID>
<a:Name>break</a:Name>
<a:Code>break</a:Code>
<a:CreationDate>1336405219</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336406182</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:ReturnType>Pattern</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o93">
<a:ObjectID>6F268F6C-E32D-457D-BAD4-A8475AC5DAA0</a:ObjectID>
<a:Name>origin</a:Name>
<a:Code>origin</a:Code>
<a:CreationDate>1336406148</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336406182</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>Pattern</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o94">
<a:ObjectID>72E34776-45AD-4BBA-9986-85A58589D3DA</a:ObjectID>
<a:Name>bonus</a:Name>
<a:Code>bonus</a:Code>
<a:CreationDate>1336406148</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336406182</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>std::list&lt;Bonus&gt;&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o95">
<a:ObjectID>96199847-BBD1-49F6-8925-CF1C61FB2CAA</a:ObjectID>
<a:Name>Map</a:Name>
<a:Code>Map</a:Code>
<a:CreationDate>1336405233</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336405954</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Constructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o96">
<a:ObjectID>A251D28E-33DA-4E52-A87E-B1CF496900B3</a:ObjectID>
<a:Name>map</a:Name>
<a:Code>map</a:Code>
<a:CreationDate>1336405917</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336405927</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>std::string</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o97">
<a:ObjectID>4DEC2ECD-A702-4C60-B3E2-AB163B8400EA</a:ObjectID>
<a:Name>x</a:Name>
<a:Code>x</a:Code>
<a:CreationDate>1336405933</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336405954</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>size_t</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o98">
<a:ObjectID>C21CEBBD-A84C-434C-AE56-BCAA42E6B531</a:ObjectID>
<a:Name>y</a:Name>
<a:Code>y</a:Code>
<a:CreationDate>1336405933</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336405954</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>size_t</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Class Ref="o28"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o99">
<a:ObjectID>8E99F43B-8947-4B21-B491-E219AB487076</a:ObjectID>
<a:Name>Map</a:Name>
<a:Code>Map</a:Code>
<a:CreationDate>1336405399</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336405967</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o100">
<a:ObjectID>22B2C13E-2059-4C1B-B2A2-46CFB0EC3E26</a:ObjectID>
<a:Name>file</a:Name>
<a:Code>file</a:Code>
<a:CreationDate>1336405956</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336405964</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>std::string</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o101">
<a:ObjectID>245C32C7-9C95-4F99-AD2F-ADFE32D9DC0A</a:ObjectID>
<a:Name>~Map</a:Name>
<a:Code>~Map</a:Code>
<a:CreationDate>1336405233</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336405345</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Destructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Class Ref="o28"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o102">
<a:ObjectID>E8077D5C-0F25-48CE-8FFC-FBF0721A5B28</a:ObjectID>
<a:Name>Duplicate</a:Name>
<a:Code>Duplicate</a:Code>
<a:CreationDate>1336405237</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336405345</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Duplicate</a:Stereotype>
<a:ReturnType>Map</a:ReturnType>
<a:Operation.Visibility>-</a:Operation.Visibility>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:ObjectReturnType>
<o:Class Ref="o28"/>
</c:ObjectReturnType>
<c:InfluentObject>
<o:Class Ref="o28"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o103">
<a:ObjectID>877A689D-B9AA-4F0B-9247-0CDBE45C27D2</a:ObjectID>
<a:Name>Map</a:Name>
<a:Code>Map</a:Code>
<a:CreationDate>1336405239</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336405345</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Copy constructor</a:Stereotype>
<a:Operation.Visibility>-</a:Operation.Visibility>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o104">
<a:ObjectID>2D4FA9B1-97F9-4794-A122-56D08921976B</a:ObjectID>
<a:Name>oldMap</a:Name>
<a:Code>oldMap</a:Code>
<a:CreationDate>1336405239</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336405345</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>const Map&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
<c:ObjectDataType>
<o:Class Ref="o28"/>
</c:ObjectDataType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Class Ref="o28"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o105">
<a:ObjectID>96F89179-C314-4295-8E1E-E5E8BC949BD2</a:ObjectID>
<a:Name>initialize</a:Name>
<a:Code>initialize</a:Code>
<a:CreationDate>1336405338</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336405338</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Override</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o33"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o106">
<a:ObjectID>87D85D53-DAEF-47FD-AB05-E739F30B54BD</a:ObjectID>
<a:Name>draw</a:Name>
<a:Code>draw</a:Code>
<a:CreationDate>1336405340</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336405340</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Override</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o107">
<a:ObjectID>B4B3D681-B1E0-4247-B01F-9CF40C89F8FD</a:ObjectID>
<a:Name>clock</a:Name>
<a:Code>clock</a:Code>
<a:CreationDate>1336405340</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336405340</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>gdl::GameClock const&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o108">
<a:ObjectID>D8F60491-E393-4119-A418-38363E2A4E17</a:ObjectID>
<a:Name>input</a:Name>
<a:Code>input</a:Code>
<a:CreationDate>1336405340</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336405340</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Parameter.DataType>gdl::Input&amp;</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Operation Ref="o34"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o109">
<a:ObjectID>74C68EF5-6E37-4464-AD6A-15096297D4BA</a:ObjectID>
<a:Name>update</a:Name>
<a:Code>update</a:Code>
<a:CreationDate>1336405342</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336405342</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Override</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o37"/>
</c:InfluentObject>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o29">
<a:ObjectID>48692D6E-E339-46B7-8465-E6BB4E86EC74</a:ObjectID>
<a:Name>Human</a:Name>
<a:Code>Human</a:Code>
<a:CreationDate>1336406694</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336407219</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Operations>
<o:Operation Id="o110">
<a:ObjectID>9805ECF0-C524-43ED-8A0C-981D8C662B55</a:ObjectID>
<a:Name>play</a:Name>
<a:Code>play</a:Code>
<a:CreationDate>1336406806</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336406806</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Override</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o53"/>
</c:InfluentObject>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o30">
<a:ObjectID>0740F002-5B85-4A44-A6B3-590C0A4F28ED</a:ObjectID>
<a:Name>AI</a:Name>
<a:Code>AI</a:Code>
<a:CreationDate>1336406696</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336407227</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Operations>
<o:Operation Id="o111">
<a:ObjectID>EEC8C180-5A87-4911-99F9-C096F2157B88</a:ObjectID>
<a:Name>play</a:Name>
<a:Code>play</a:Code>
<a:CreationDate>1336407021</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336407021</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:Stereotype>Override</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o53"/>
</c:InfluentObject>
</o:Operation>
</c:Operations>
</o:Class>
</c:Classes>
<c:Generalizations>
<o:Generalization Id="o8">
<a:ObjectID>2FE8F85B-CC30-404A-AEE9-EEF57021657E</a:ObjectID>
<a:Name>Generalisation_1</a:Name>
<a:Code>Generalisation_1</a:Code>
<a:CreationDate>1336403784</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336403872</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<c:Object1>
<o:Class Ref="o24"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o25"/>
</c:Object2>
</o:Generalization>
<o:Generalization Id="o11">
<a:ObjectID>92C703D4-E215-439C-BDDC-65948A21D6F9</a:ObjectID>
<a:Name>Generalisation_2</a:Name>
<a:Code>Generalisation_2</a:Code>
<a:CreationDate>1336404390</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404467</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<c:Object1>
<o:Class Ref="o24"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o26"/>
</c:Object2>
</o:Generalization>
<o:Generalization Id="o14">
<a:ObjectID>280D6E8D-D6E6-41D0-80BF-8260CEA1D77E</a:ObjectID>
<a:Name>Generalisation_3</a:Name>
<a:Code>Generalisation_3</a:Code>
<a:CreationDate>1336404858</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336404900</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<c:Object1>
<o:Class Ref="o24"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o27"/>
</c:Object2>
</o:Generalization>
<o:Generalization Id="o17">
<a:ObjectID>BB75FDD6-8AFA-4B1A-9B59-850CE23B4F13</a:ObjectID>
<a:Name>Generalisation_4</a:Name>
<a:Code>Generalisation_4</a:Code>
<a:CreationDate>1336405087</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336405090</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<c:Object1>
<o:Class Ref="o24"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o28"/>
</c:Object2>
</o:Generalization>
<o:Generalization Id="o20">
<a:ObjectID>0CA62D60-A683-44D4-952C-9A3AE61F9C03</a:ObjectID>
<a:Name>Generalisation_5</a:Name>
<a:Code>Generalisation_5</a:Code>
<a:CreationDate>1336406777</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336406812</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<c:Object1>
<o:Class Ref="o25"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o29"/>
</c:Object2>
</o:Generalization>
<o:Generalization Id="o23">
<a:ObjectID>2B61F1F7-8CC8-47AC-9936-D6A5EA47071C</a:ObjectID>
<a:Name>Generalisation_6</a:Name>
<a:Code>Generalisation_6</a:Code>
<a:CreationDate>1336406869</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336407023</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<c:Object1>
<o:Class Ref="o25"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o30"/>
</c:Object2>
</o:Generalization>
</c:Generalizations>
<c:TargetModels>
<o:TargetModel Id="o112">
<a:ObjectID>1E09A698-04F1-49CA-A912-339F201A7FBB</a:ObjectID>
<a:Name>C++</a:Name>
<a:Code>C++</a:Code>
<a:CreationDate>1336393137</a:CreationDate>
<a:Creator>Fiahil</a:Creator>
<a:ModificationDate>1336393137</a:ModificationDate>
<a:Modifier>Fiahil</a:Modifier>
<a:TargetModelURL>file:///%_OBJLANG%/C++.xol</a:TargetModelURL>
<a:TargetModelID>22FB523D-7E45-430F-8069-3A702CF3BE3C</a:TargetModelID>
<a:TargetModelClassID>1811206C-1A4B-11D1-83D9-444553540000</a:TargetModelClassID>
<c:SessionShortcuts>
<o:Shortcut Ref="o3"/>
</c:SessionShortcuts>
</o:TargetModel>
</c:TargetModels>
</o:Model>
</c:Children>
</o:RootObject>

</Model>