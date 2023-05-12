object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1044#1074#1080#1078#1077#1085#1080#1077' '#1090#1077#1083#1072
  ClientHeight = 361
  ClientWidth = 783
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 423
    Top = 174
    Width = 50
    Height = 13
    Caption = #1052#1072#1090#1077#1088#1080#1072#1083
  end
  object Chart1: TChart
    Left = 8
    Top = 8
    Width = 409
    Height = 345
    Legend.Visible = False
    Title.Text.Strings = (
      'TChart')
    View3D = False
    TabOrder = 0
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series1: TFastLineSeries
      LinePen.Color = 10708548
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object LabeledEdit1: TLabeledEdit
    Left = 425
    Top = 24
    Width = 172
    Height = 21
    EditLabel.Width = 104
    EditLabel.Height = 13
    EditLabel.Caption = #1053#1072#1095#1072#1083#1100#1085#1072#1103' '#1089#1082#1086#1088#1086#1089#1090#1100
    TabOrder = 1
    Text = '30'
  end
  object LabeledEdit2: TLabeledEdit
    Left = 425
    Top = 64
    Width = 172
    Height = 21
    EditLabel.Width = 74
    EditLabel.Height = 13
    EditLabel.Caption = #1059#1075#1086#1083' '#1073#1088#1086#1089#1072#1085#1080#1103
    TabOrder = 2
    Text = '60'
  end
  object LabeledEdit3: TLabeledEdit
    Left = 423
    Top = 104
    Width = 172
    Height = 21
    EditLabel.Width = 66
    EditLabel.Height = 13
    EditLabel.Caption = #1064#1072#1075' '#1074#1088#1077#1084#1077#1085#1080
    TabOrder = 3
    Text = '0.1'
  end
  object LabeledEdit4: TLabeledEdit
    Left = 423
    Top = 147
    Width = 172
    Height = 21
    EditLabel.Width = 65
    EditLabel.Height = 13
    EditLabel.Caption = #1056#1072#1076#1080#1091#1089' '#1096#1072#1088#1072
    TabOrder = 4
    Text = '0.05'
  end
  object ComboBox1: TComboBox
    Left = 423
    Top = 193
    Width = 172
    Height = 21
    ItemIndex = 0
    TabOrder = 5
    Text = #1050#1072#1084#1077#1085#1100
    Items.Strings = (
      #1050#1072#1084#1077#1085#1100
      #1055#1077#1085#1086#1087#1083#1072#1089#1090
      #1044#1077#1088#1077#1074#1086
      #1046#1077#1083#1077#1079#1086)
  end
  object LabeledEdit5: TLabeledEdit
    Left = 603
    Top = 24
    Width = 172
    Height = 21
    EditLabel.Width = 89
    EditLabel.Height = 13
    EditLabel.Caption = #1055#1083#1086#1090#1085#1086#1089#1090#1100' '#1089#1088#1077#1076#1099
    TabOrder = 6
    Text = '1.205'
  end
  object LabeledEdit6: TLabeledEdit
    Left = 603
    Top = 64
    Width = 172
    Height = 21
    EditLabel.Width = 157
    EditLabel.Height = 13
    EditLabel.Caption = #1044#1080#1085#1072#1084#1080#1095#1077#1089#1082#1072#1103' '#1074#1103#1079#1082#1086#1089#1090#1100' '#1089#1088#1077#1076#1099
    TabOrder = 7
    Text = '0.0000181'
  end
  object CheckBox1: TCheckBox
    Left = 603
    Top = 91
    Width = 172
    Height = 17
    Caption = #1059#1095#1080#1090#1099#1074#1072#1090#1100' '#1087#1086#1082#1072#1079#1072#1090#1077#1083#1080' '#1089#1088#1077#1076#1099
    Checked = True
    State = cbChecked
    TabOrder = 8
  end
  object Button1: TButton
    Left = 649
    Top = 114
    Width = 75
    Height = 25
    Caption = #1055#1086#1089#1090#1088#1086#1080#1090#1100
    TabOrder = 9
    OnClick = Button1Click
  end
end
