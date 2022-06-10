object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 15
  object Label1: TLabel
    Left = 19
    Top = 8
    Width = 357
    Height = 15
  end
  object Memo1: TMemo
    Left = 8
    Top = 32
    Width = 385
    Height = 241
    ReadOnly = True
    TabOrder = 0
  end
  object Button1: TButton
    Left = 408
    Top = 40
    Width = 75
    Height = 25
    Caption = 'Read FS Info'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 408
    Top = 88
    Width = 75
    Height = 25
    Caption = 'Clear'
    TabOrder = 2
    OnClick = Button2Click
  end
end
